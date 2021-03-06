/*
    Rachel A Schifano
 
    1. Count number of words in file
    2. Count number of lines in file
*/

#include <stdio.h>
#include <string.h>

char *t1;
int words = 0;
int lines = 0;
int total_words = 0;

main(int argc, char *argv[])
{
	/* Open a file and read it */
	FILE *file;
	char *filename = argv[1];

	/* open the file for reading */
	file = fopen(filename, "r");
	if (file == NULL) {
		fprintf(stderr, "File %s could not be opened\n", filename);
		exit(1);
	}
	/* loop while reading a line at a time from the file and printing */
	char buffer[200];
	while (1) {
		fgets(buffer, 200, file); /* gets a line up to 200 characters */
		
		if (!feof(file)) {
			lines++;
		}
		else {
			break; /* if EOF, break out of loop */
		}
		total_words = count_words(buffer);
	}
	/* print totals to the console */
	printf("Number of lines: %d\n", lines);
	printf("Number of words: %d\n", total_words);

	/* close the file */
	fclose(file);	
}
/* Function that counts the number of words per buffer */
int count_words(char buffer[]) {
	/* Count number of words */
	for (t1 = strtok(buffer," "); t1 != NULL; t1 = strtok(NULL," "))
	{
		words++;
	}
	return words;
}
