#include "monty.h"

int main(int argc, char**argv)
{
	FILE *file;
	size_t bufsize = 1024;
	ssize_t characters;
	char *buffer;
	char **arguments;
	unsigned int line_n = -1;

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
		line_n++;
		if (buffer[characters - 1] == '\n')
			buffer[characters - 1] = 0;
		arguments = str_to_arguments(buffer, ' ');
		if (!arguments)
			continue;
		if (arguments[0][0] == '#')
			continue;
		do_func(arguments[0], arguments[1], line_n, stack);
		free(arguments);
	}
	free(buffer);
	fclose(file);
	return (0);
}

void do_func(char *command, char *argument, unsigned int line_n, stack_t **stack)
{
	
}
