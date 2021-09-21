#include "monty.h"

int main(int argc, char**argv)
{
	FILE *file;
	size_t bufsize = 1024;
	ssize_t characters;
	char *buffer;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[0]);
		return (EXIT_FAILURE);
	}
	buffer = malloc(bufsize);
	if (!buffer)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(file);
		return (EXIT_FAILURE);
	}

	while ((characters = getline(&buffer, &bufsize, file)) != -1)
	{
		if (buffer[characters - 1] == '\n')
			buffer[characters - 1] = 0;
		printf("line: %s\n", buffer);
	}
	free(buffer);
	fclose(file);
	return (0);
}
