#include "monty.h"
/**
  *f_pop - function
  *@stack: stack
  *@line_number: line number
  *Return: nothing
  */
void f_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *nex;
	if (!*stack)
	{
		fprintf(stderr, "L%i: can't pop an empty stack\n", line_number);
		_ex(stack, NULL);
	}
	nex = (*stack)->next;
	free(*stack);
	*stack = nex;
}
/**
  *f_swap - function
  *@stack: stack
  *@line_number: line number
  *Return: nothing
  */
void f_swap(stack_t **stack, __attribute__ ((unused)) unsigned int line_number)
{
	printf("stack: %p l_num: %i", (void *)stack, line_number);
}
/**
  *f_add - function
  *@stack: stack
  *@line_number: line number
  *Return: nothing
  */
void f_add(stack_t **stack, __attribute__ ((unused)) unsigned int line_number)
{
	printf("stack: %p l_num: %i", (void *)stack, line_number);
}
