/*
	CSC 415 HW#5- Producer-Consumer Problem
	Parker Gray
*/

#include <fcntl.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

sem_t full;
sem_t empty;
pthread_mutex_t lock;

struct producerDataStruct
{				//for use by producers and in produce funct
  int thread_number;		//tid of the producer thread
  int num_produced;
};

struct consumerDataStruct
{
  int thread_number;
  int num_consumed;
};

typedef struct bufferStack
{
  int *elements;		//int array
  int capacity;			//capacity refers to the total number of indices available to be filled.
  int size;			//size refers to the current number of filled indices in stack.
} bufferStack;

bufferStack buffer;

void
push (bufferStack * stack, int element)
{
  if (stack->size != stack->capacity)
    {				//if # of filled indices isn't equal to 16 (in the case of this assign)
      stack->elements[stack->size] = element;	//place element at the next available empty index
      stack->size++;		//iterate size
    }
  else
    {
      exit (1);
    }
}

int
pop (bufferStack * stack)
{
  int top;
  if (stack->size != 0)
    {				//if there exist filled indices
      stack->size--;		//subtract size
      top = stack->elements[stack->size];	//get the element at size-1.
    }
  else
    {
      exit (1);
    }
  return top;
}

void *
producer (void *param)
{
  struct producerDataStruct *data = (struct producerDataStruct *) param;	//get data from producerData
  int item;			//item to be produced
  int counter = 0;
  while (counter < data->num_produced)
    {
      item = data->thread_number * data->num_produced + counter;	//the equation for item_produced outlined in the assignment instructions
      sem_wait (&empty);
      pthread_mutex_lock (&lock);
      push (&buffer, item);
      pthread_mutex_unlock (&lock);
      sem_post (&full);
      counter++;
    }
  pthread_exit (NULL);
}

void *
consumer (void *param)
{
  struct consumerDataStruct *data = (struct consumerDataStruct *) param;
  int consumerIndex = data->thread_number;
  int numConsumed = data->num_consumed;
  int item;
  int i = 0;
  while (i < numConsumed)
    {
      sem_wait (&full);
      pthread_mutex_lock (&lock);
      item = pop (&buffer);
      pthread_mutex_unlock (&lock);
      sem_post (&empty);
      printf ("consumer %d consumes %d\n", consumerIndex, item);
      i++;
    }
  pthread_exit (NULL);
}

int
main (int argc, char *argv[])
{
  //before continuing, check to make sure the user used the command line as the program requires
  if (argc != 4)
    {				//if argument num is not 2....
      fprintf (stderr,
	       "Wrong usage. Please use the program like so: ./a.out <int> <int> <int>\n");
      return 1;			//return an error message and quit.
    }
  //following section pretty much self explanatory
  int num_producers = atoi (argv[1]);
  int num_consumers = atoi (argv[2]);
  int num_total_produced = atoi (argv[3]);
  int num_threads = num_producers + num_consumers;
  int produced_per_thread = num_total_produced / num_producers;
  int consumed_per_thread = num_total_produced / num_consumers;
  int i = 0;
  pthread_t *producers =
    (pthread_t *) malloc (num_producers * sizeof (pthread_t));
  pthread_t *consumers =
    (pthread_t *) malloc (num_consumers * sizeof (pthread_t));
  struct producerDataStruct *producerData =
    (struct producerDataStruct *) malloc (num_producers *
					  sizeof (struct producerDataStruct));
  struct consumerDataStruct *consumerData =
    (struct consumerDataStruct *) malloc (num_consumers *
					  sizeof (struct consumerDataStruct));


  buffer.elements = (int *) malloc (16 * sizeof (int));
  buffer.capacity = 16;
  buffer.size = 0;

  sem_init (&full, 0, 0);
  sem_init (&empty, 0, 16);

  if (pthread_mutex_init (&lock, NULL) != 0)
    {
      fprintf (stderr, "Failed to initialize mutex. Please restart\n");
      return 1;
    }

  printf
    ("Number of producer threads: %i. Number of consumer threads: %i. Items to produce: %i.\n",
     num_producers, num_consumers, num_total_produced);

  while (i < num_producers)
    {				//create producers.
      producerData[i].thread_number = i;
      producerData[i].num_produced = produced_per_thread;
      if (pthread_create (&producers[i], NULL, &producer, &producerData[i]) !=
	  0)
	{
	  fprintf (stderr, "Couldn't create producer w/ ID#%i.\n", i);
	  return 1;
	}
      i++;
    }

  i = 0;			//reestablish i = 0 after it was used in previous while loop
  while (i < num_consumers)
    {				//create consumers.
      consumerData[i].thread_number = i;
      consumerData[i].num_consumed = consumed_per_thread;
      if (pthread_create
	  (&consumers[i], NULL, &consumer, &consumerData[i]) != 0)
	{
	  fprintf (stderr, "Couldn't create consumer w/ ID#%i.\n", i);
	  return 1;
	}
      i++;
    }
  //below section joins producer/consumer threads.
  i = 0;
  while (i < num_producers)
    {
      pthread_join (producers[i], NULL);
      i++;
    }

  i = 0;
  while (i < num_consumers)
    {
      pthread_join (consumers[i], NULL);
      i++;
    }
  //free p_threads and destroy all semaphore related variables.
  free (producers);
  free (consumers);
  free (producerData);
  free (buffer.elements);
  pthread_mutex_destroy (&lock);
  sem_destroy (&full);
  sem_destroy (&empty);

  printf ("Execution completed!\n");

  return 0;
}
