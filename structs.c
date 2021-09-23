#include "monty.h"

/**
  *free_s - function
  *@stack: stack
  *Return: nothing
  */
void free_s(stack_t **stack)
{
	stack_t *ptr, *next;

	if (!stack)
		return;
	ptr = *stack;
	while (ptr)
	{
		next = ptr->next;
		free(ptr);
		ptr = next;
	}
}
/**
  *found_f - function
  *@str: stack
  *Return: nothing
  */
instruction_t found_f(char *str)
{
	int i;
	instruction_t comms[] = {
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
		if (strcmp(str, comms[i].opcode) == 0)
			break;
	return (comms[i]);
}
/**
  *_ex - function
  *@stack: stack
  *@str: line number
  *Return: nothing
  */
void _ex(stack_t **stack, char *str)
{
	if (str)
		fprintf(stderr, "%s", str);
	free_s(stack);
	exit(EXIT_FAILURE);
}
/**
  *is_num - function
  *@str: stack
  *Return: nothing
  */
int is_num(char *str)
{
	int found;

	found = 1;
	if ((size_t)snprintf(NULL, 0, "%d", atoi(str)) != strlen(str))
		found--;
	return (found);
}
