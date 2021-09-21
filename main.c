#include "monty.h"

int do_func(char *command, char *argument, unsigned int line_n, stack_t **stack);
void free_s(stack_t **stack)
{
	stack_t *ptr;

	ptr = *stack;
	while (ptr)
	{
		free(ptr);
		ptr = ptr->next;
	}
}
int main(int argc, char**argv)
{
	FILE *file;
	size_t bufsize = 1024;
	ssize_t characters;
	char *buffer;
	char **arguments;
	unsigned int line_n = -1;
	int error;

	stack_t *stack_o = NULL;
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
		error = do_func(arguments[0], arguments[1], line_n, &stack_o);
		free(arguments);
		if (error != 0)
			break;
	}
	free_s(&stack_o);
	free(buffer);
	fclose(file);
	return (0 ? !error : EXIT_FAILURE);
}

int do_func(char *command, char *argument, unsigned int line_n, stack_t **stack)
{
	int i, found = 0;
	instruction_t comms[] =
	{
		{"push", &f_push},
		{"pall", &f_pall},
		{"pint", &f_pint},
		{"pop", &f_pop},
		{"swap", &f_swap},
		{"add", &f_add},
		{"nop", &f_nop},
		{"sub", &f_sub},
		{"div", &f_div},
		{"mul", &f_mul},
		{"mod", &f_mod},
		{"pchar", &f_pchar},
		{"pstr", &f_pstr},
		{"rotl", &f_rotl},
		{"rotr", &f_rotr},
		{"stack", &f_stack},
		{"queue", &f_queue},
		{NULL, NULL}
	};
	
	for (i = 0; comms[i].opcode; i++)
	{
		if (strcmp(command, comms[i].opcode) == 0)
		{
			if (i == 0)
			{
				if (argument)
				{
					(comms[i].f)(stack, line_n);
					(*stack)->n = atoi(argument);
				}
				else
				{
					fprintf(stderr, "L%i: usage: push integer\n", line_n);
					return (1);
				}
			}
			else
				(comms[i].f)(stack, line_n);
			found = 1;
		}
	}
	if (!found)
	{
		fprintf(stderr, "L%i: unknown instruction %s\n", line_n, command);
		return (1);
	}
	return (0);
}
