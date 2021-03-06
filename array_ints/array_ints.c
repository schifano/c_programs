/*
    Rachel A Schifano
 
    1. Retrieves ten integers as keyboard input from the user.
    2. Prints out ints to the console in reverse order.
    3. Prints out ints to a file in reverse order. 
*/

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
extern int errno;

main() {
	/* instantiate variables */
	char input[150], output[15];
	int array[10];
	int fd;

	/* Take each integer keyboard input from the user and store it in the integer array */
	int i;
	for (i = 0; i < 10; i++) {
		read(fileno(stdin), input, 150);
		array[i] = atoi(input);
	}

	/* Create file */
	if ((fd = open("output.txt", O_RDWR | O_CREAT, 0600)) == -1) 
	{
		fprintf(stderr, "Unable to open file. %s\n", strerror(errno));
		return;
	}

	/* Output array contents to a file in reverse order */
	int j;	
	for (j = 10; j > 0; j--) {
		sprintf(output,"%i",array[j-1]); /* take each integer and store into character array */
		write(fileno(stdout),output,strlen(output));
		write(fileno(stdout),"\n",1);
		write(fd,output,strlen(output));
		write(fd,"\n",1);	
	}
	close(fd);
}
