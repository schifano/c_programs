/*
	Rachel A Schifano
*/
#include <stdio.h>
int main() {

	FILE *file; /* Create file pointer */
	char *filename = "test.txt";

	/* open the file for writing */
	file = fopen(filename, "w");
	if (file == NULL) {
		fprintf(stderr, "File %s could not be opened\n", filename);
		exit(1);
	}

	/* write to the file */
	fprintf(file, "Hello World!\n");

	/* close the file */
	fclose(file);

	return 0;
}
