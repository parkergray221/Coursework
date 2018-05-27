/*
	CSC 415 Assignment 6: Copy File
	Parker Gray
	12/6/17
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUFSIZE 1024

char buf[BUFSIZE];

int main(int argc, char *argv[]){
	    //before continuing, check to make sure the user used the command line as the program requires
    if(argc != 3){ //if argument num is not 2....
        fprintf(stderr,"Wrong usage. Please use the program like so: ./a.out <file1 path>  <file2 path> \n");
        return -1; //return an error message and quit.
    }
	    
	int inputFile;
    inputFile = open(argv[1], O_RDONLY);  //open the file in read only mode. 

    if(inputFile == -1){ //if file somehow couldn't open.
        fprintf(stderr, "Couldn't open the input file. Try again. Be sure that file1's location is correct and in this format: ./a.out <file1 path>  <file2 path> \n");
        return -1;
    	}
	
	int outputFile;
	outputFile = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, S_IRWXU); //after successful opening of file1, open (create) file2. 
	//if file2 already exists in the directory then open fails. 
	
	if(outputFile == -1){
		fprintf(stderr, "Couldn't create the output file. If file2 already exists within the working directory, delete it and try running again. \n");
		return -1;
	}

	int numBytesRead; 
	numBytesRead = read(inputFile, buf, BUFSIZE); //read() returns the number of bytes read. this line will read from file1 until the buffer is filled
	//or the end of file is reached. store this value into numBytesRead.
	
	if(numBytesRead == -1){ //if file length somehow couldn't be read.
	fprintf(stderr, "Reading the input file went wrong. Try again. \n");
    	}
	
	write(outputFile, buf, numBytesRead); //write the contents of buf to outputFile.
	printf("copied %d bytes \n", numBytesRead);
	int closeInput = close(inputFile);
	int closeOutput = close(outputFile);
	if(closeInput == -1 || closeOutput == -1){
		fprintf(stderr, "Something went wrong when closing either the input or output file. Regardless, if you made it this far the output file should \
		contain the input file's contents and the number of bytes read should have been printed. Yay! \n");
		return -1;
	}
	return 0;
}
