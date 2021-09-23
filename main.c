#include "monty.h"

/**
  *do_comm - function
  *@stack: stack
  *@comm: line number
  *@num: num
  *@line_n: line_n
  *Return: nothing
  */
void do_comm(stack_t **stack, instruction_t comm, int num, unsigned int line_n)
{
	(comm.f)(stack, line_n);
	if (strcmp(comm.opcode, "push") == 0)
		(*stack)->n = num;
}
/**
  *get_line- function
  *@line_n: stack
  *@filename: line number
  *@stack: stack
  *Return: nothing
  */
char **get_line(unsigned int line_n, char *filename, stack_t **stack)
{
	char *buffer;
	size_t bufsize = 1024;
	ssize_t characters;
	FILE *file;
	char **arguments;
	unsigned int i;

	buffer = malloc(bufsize + 1);
	if (!buffer)
		_ex(stack, "Error: malloc failed\n");
	file = fopen(filename, "r");
	for (i = 0; i < (line_n); i++)
		characters = getline(&buffer, &bufsize, file);
	if (file)
		fclose(file);
	if (characters == -1)
	{
		free(buffer);
		free_s(stack);
		exit(0);
	}
	if (buffer[characters - 1] == '\n')
		buffer[characters - 1] = 0;
	arguments = str_to_arguments(buffer, ' ');
	free(buffer);
	return (arguments);
}
/**
  *read_file - function
  *@filename: stack
  *Return: nothing
  */
void read_file(char *filename)
{
	stack_t *stack_o = NULL;
	char **arguments;
	unsigned int line_n;
	instruction_t comm;
	int num, is_n = 1;

	for (line_n = 1; ; line_n++)
	{
		arguments = get_line(line_n, filename, &stack_o);
		if (arguments[0][0] == '#' || !arguments[0][0])
		{
			free_args(arguments);
			continue;
		}
		comm = found_f(arguments[0]);
		if (!comm.opcode)
		{
			fprintf(stderr, "L%i: unknown instruction %s\n", line_n, arguments[0]);
			free_args(arguments);
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
/**
  *main - function
  *@argc: stack
  *@argv: line number
  *Return: nothing
  */
int main(int argc, char **argv)
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
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	if (file)
		fclose(file);
	read_file(argv[1]);
	return (0);
}
