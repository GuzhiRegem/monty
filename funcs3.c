#include "monty.h"

/**
  *f_nop - function
  *@stack: stack
  *@line_number: line number
  *Return: nothing
  */
void f_nop(stack_t **stack, unsigned int line_number)
{
	stack = stack;
	line_number = line_number;
}
/**
  *f_sub - function
  *@stack: stack
  *@line_number: line number
  *Return: nothing
  */
void f_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *first = NULL, *second = NULL;

	first = *stack;
	if (first)
		second = first->next;
	if (!first || !second)
	{
		fprintf(stderr, "L%i: can't sub, stack too short\n", line_number);
		_ex(stack, NULL);
	}
	second->n -= first->n;
	free(first);
	second->prev = NULL;
	*stack = second;
}
/**
  *f_div - function
  *@stack: stack
  *@line_number: line number
  *Return: nothing
  */
void f_div(stack_t **stack, unsigned int line_number)
{
	stack_t *first = NULL, *second = NULL;

	first = *stack;
	if (first)
		second = first->next;
	if (!first || !second)
	{
		fprintf(stderr, "L%i: can't div, stack too short\n", line_number);
		_ex(stack, NULL);
	}
	if (!first->n)
	{
		fprintf(stderr, "L%i: division by zero\n", line_number);
		_ex(stack, NULL);
	}
	second->n /= first->n;
	free(first);
	second->prev = NULL;
	*stack = second;

}
