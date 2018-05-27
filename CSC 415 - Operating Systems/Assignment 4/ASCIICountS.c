/*
	CSC 415 HW#4- ASCII Character Count w/ Mutex Lock
	Parker Gray
*/

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#define BUFSIZE 65536 //buffer size of 64kb
#define NUMTHREADS 8 //number of child threads to create
#define ASCIICHARNUM 128 //number of characters in ascii table

char buf[BUFSIZE]; //buffer to hold content of file
int childArray[ASCIICHARNUM]; //array for child threads to store ascii character counts
//int parentArray[NUMTHREADS][ASCIICHARNUM]; parentArray not necessary for this assignment
void *charCounter(void *param); //child threads run this function. it records characters and counts them for printing.
pthread_mutex_t mutex; //declare mutex

typedef struct  
{
    int tid; //the tid for the child thread
    int childPartitionSize; //the size/endpoint of the partition for a particular child thread
}childThreadStruct;

void *charCounter(void *param) //the function that child threads will run when they are created.
{
    childThreadStruct* childStruct = (childThreadStruct*) param; //get the values passed to charCounter
    int locationInFile = childStruct->tid * childStruct->childPartitionSize; //the location of the childThread in the file is the size of partition times the id of the childThread.
    int currentCharacter = buf[locationInFile]; //holds the current character at location in character buffer file was loaded into.

    for (int i=0; i < childStruct->childPartitionSize && locationInFile < BUFSIZE; i++){ //for that continues until i reaches the end of the partition or the end of the buffer.
        currentCharacter = buf[locationInFile++];  //get currentCharacter to be the childArray's location in the file.
	pthread_mutex_lock(&mutex);
        childArray[currentCharacter]++; //tally up the [column] associated with the currently running child thread and the column of the character read.
	pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    //before continuing, check to make sure the user used the command line as the program requires
    if(argc != 2){ //if argument num is not 2....
        fprintf(stderr,"Wrong usage. Please use the program like so: ./a.out c://directory/filename \n");
        return -1; //return an error message and quit.
    }
	
    int file;
    file = open(argv[1], O_RDONLY);  //open the file in read only mode. 

    if(file == -1){ //if file somehow couldn't open.
        fprintf(stderr, "Couldn't open the file. Try again. Be sure to use the following terminal command: ./a.out c://directory/filename \n");
        return -1;
    }
	
    size_t fileLength; //the number of kilobytes the file is.
    fileLength = read(file, buf, BUFSIZE); //read the characters of file and place them into character buffer array buf. fill the buffer until 64KB limit is met. set fileLength to be length of the file as is stored in buf.
	
    if(fileLength == -1){ //if file length somehow couldn't be read.
	fprintf(stderr, "Reading the file went wrong. Try again. \n");
    }
	
    close(file); //close the file after the file has been read.
    int partition = (double) fileLength / (double) NUMTHREADS; //create a partition by dividing the fileLength by 8.
    printf("%i threads with partition size of %i\n", NUMTHREADS, partition);

    pthread_t tid[NUMTHREADS]; //array that holds thread identifiers for child threads.
    pthread_attr_t attr; //define attributes for child threads.
    pthread_attr_init(&attr); //initialize child thread attributes to default.
    childThreadStruct childThreads[NUMTHREADS]; //array that holds childThread Structs
    pthread_mutex_init(&mutex, NULL); //initialize mutex lock

    for (int i=0; i<NUMTHREADS; i++) {
        childThreads[i].tid = i; //set the tid to the current iteration of i.
        childThreads[i].childPartitionSize = partition; //every child thread will have the same partition size.
        pthread_create(&tid[i], &attr, charCounter, &childThreads[i]); //each child thread starts up charCounter with its own struct values.
    }

    for (int i=0; i<NUMTHREADS; i++){ //join the created childThreads
        pthread_join(tid[i], NULL); //execute charCounter here after joining each 
    }

    int sumChar; //a variable used to sum up the occurrence of a character found from child threads in the for loop below.
	
    for (int j=0; j< ASCIICHARNUM; j++){ //column
            sumChar = childArray[j]; 
        
		printf("%i occurences of ", sumChar); //print out sum as the number of occurrences of a character.

		if (j<=32 || j==127) printf("0x%02x\n", j); //and print out the character sum is associated with.
		else printf("%c\n", j);
    }
	
    return 0;
}

