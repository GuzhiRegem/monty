#include "monty.h"

/**
  *f_push - function
  *@stack: stack
  *@line_number: line number
  *Return: nothing
  */
void f_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	line_number = line_number;
	new = malloc(sizeof(stack_t));
	if (!new)
		_ex(stack, "Error: malloc failed\n");
	new->next = *stack;
	new->prev = NULL;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}
/**
  *f_pall - function
  *@stack: stack
  *@line_number: line number
  *Return: nothing
  */
void f_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = *stack;

	if (stack != NULL || *stack != NULL)
	{
		line_number = line_number;
		while (new_node != NULL)
		{
			printf("%d\n", new_node->n);
			new_node = new_node->next;
		}
	}
}
/**
  *f_pint - function
  *@stack: stack
  *@line_number: line number
  *Return: nothing
  */
void f_pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%i: can't pint, stack empty\n", line_number);
		free_s(stack);
		exit(EXIT_FAILURE);
	}

	printf("%i\n", (*stack)->n);
}
