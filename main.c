#include "monty.h"

void do_comm(stack_t **stack, instruction_t comm, int num, unsigned int line_n)
{
	(comm.f)(stack, line_n);
	if (strcmp(comm.opcode, "push") == 0)
		(*stack)->n = num;
}
void read_file(char *filename)
{
	stack_t *stack_o = NULL;
	char *buffer;
	char **arguments;
	ssize_t characters = 0;
	size_t bufsize = 1024;
	unsigned int line_n, i;
	instruction_t comm;
	int num, is_n = 1;
	FILE *file;

	for (line_n = 0;;line_n++)
	{
		buffer = malloc(bufsize);
		if (!buffer)
			_ex(&stack_o, "Error: malloc failed\n");
		file = fopen(filename, "r");
		for (i = 0; i < (line_n + 1); i++)
			characters = getline(&buffer, &bufsize, file);
		fclose(file);
		if (characters == -1)
		{
			free(buffer);
			break;
		}
		if (buffer[characters - 1] == '\n')
			buffer[characters - 1] = 0;
		arguments = str_to_arguments(buffer, ' ');
		free(buffer);
		if (arguments[0][0] == '#' || !arguments[0][0])
		{
			free_args(arguments);
			continue;
		}
		comm = found_f(arguments[0]);
		if (!comm.opcode)
		{
			free_args(arguments);
			fprintf(stderr, "L%i: unknown instruction\n", line_n);
			_ex(&stack_o, NULL);
		}	
		if (arguments[1])
		{
			is_n = is_num(arguments[1]);
			num = atoi(arguments[1]);
		}
		if ((strcmp(comm.opcode, "push") == 0) && (!is_n || !arguments[1]))
		{
			free_args(arguments);
			fprintf(stderr, "L%i: usage: push integer\n", line_n);
			_ex(&stack_o, NULL);
		}
		free_args(arguments);
		do_comm(&stack_o, comm, num, line_n);
	}
	free_s(&stack_o);
}
int main(int argc, char**argv)
{
	FILE *file;

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
	fclose(file);
	read_file(argv[1]);
	return (0);
}
