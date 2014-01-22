/* 
	Name: Rachel A Schifano
	Professor: Dr. Suh
	Course: IT 383
	Program 0: Program replicates the functions of cat; concatenates files.

	NOTES: fopen/open, fclose/close, fread/read, fwrite/write
	compile cc -o my_cat my_cat.c
	ssh -X (your ulid)@ironside.idk.ilstu.edu
 */
#include <stdio.h>
#include <string.h>

int main(void) {
	char input[300]; /* store input substring */
	char * p_file = input + 3; /* pointer for removing "cat" */

	fgets(input, 300, stdin); /* Retrieve user input */

 	/* Replace \n with NUL terminator \0 so that fopen works */
	char *p_chr_nul = strchr(input, '\n'); 
	if(p_chr_nul !=NULL)
	{
		*p_chr_nul = '\0';
	}

	/* Divide string into tokens */
	const char space[2] = " ";
	char *token; /* pointer to beginning of each token */

	token = strtok(p_file, space); /* get the first token */
	while( token != NULL)		   /* walk through each token */
	{
		/* printf(" \\%s", token); */
		/* puts(token); TEST TEST TEST */
		
		FILE *file; /* File pointer to keep track of the file opened */
		int c; /* tracks each character retrieved from stream */
		/* READ and PRINT file content to command line */
		if ((file = fopen(token, "r")) != NULL) {
			file = fopen(token,"r");
			while(1)
			{
				c = fgetc(file); /* advances/gets the next character from stream */
				if( feof(file) ) /* points to file object, tests for end of file */
				{ 
					break ;
				}
				printf("%c", c); /* sends formatted output to stdout */
			}
			printf("\n"); /* for nice formatting between file outputs */
			fclose(file); /* close file */
		}
		else {
			printf("An error has occurred.");
			return 0;
		}
		token = strtok(NULL, space);
	}

	/* don't we have to catch a final character or something? */
	return 0; /* end program */
}