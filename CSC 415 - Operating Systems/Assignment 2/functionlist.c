#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFSIZE 1024

int
main ()
{
  char buf[BUFSIZE];		//integer buffer to hold the input of user
  int check = 0;
  int pid = 0;			//process id for parent/child processes
  do
    {

      printf ("1. Hello World!\n2. List files\n3. Exit\nPlease select: ");
      fgets (buf, 1024, stdin);	//store user input into buf
      char x = buf[0];

      if (x == '1')
	{
	  pid = fork ();
	  if (pid < 0)
	    {			//fork failure
	      fprintf (stderr, "Fork Failed");
	      return 1;
	    }
	  else if (pid == 0)
	    {			//child process
	      printf ("Hello world!\n");
	      exit (0);
	      //kill(pid, SIGKILL);
	    }
	  else
	    {			//parent process
	      wait (NULL);
	    }
	}
      else if (x == '2')
	{
	  pid = fork ();
	  if (pid < 0)
	    {			//fork failure
	      fprintf (stderr, "Fork Failed");
	      return 1;
	    }
	  else if (pid == 0)
	    {			//child process
	      execlp ("/bin/ls", "ls", NULL);
	      //kill(pid, SIGKILL);
	    }
	  else
	    {			//parent process
	      wait (NULL);
	    }
	}
      else if (x == '3')
	{
	  exit (0);
	}
      else
	{
	  printf ("You didn't input 1, 2, or 3. Try again.\n");
	}
    }
  while (1);

  return 0;

}
