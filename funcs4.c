#include "monty.h"

/**
  *f_mul - function
  *@stack: stack
  *@line_number: line number
  *Return: nothing
  */
void f_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *first = NULL, *second = NULL;

	first = *stack;
	if (first)
		second = first->next;
	if (!first || !second)
	{
		fprintf(stderr, "L%i: can't mul, stack too short\n", line_number);
		_ex(stack, NULL);
	}
	second->n *= first->n;
	free(first);
	second->prev = NULL;
	*stack = second;
}
/**
  *f_mod - function
  *@stack: stack
  *@line_number: line number
  *Return: nothing
  */
void f_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *first = NULL, *second = NULL;

	first = *stack;
	if (first)
		second = first->next;
	if (!first || !second)
	{
		fprintf(stderr, "L%i: can't mod, stack too short\n", line_number);
		_ex(stack, NULL);
	}
	if (!first->n)
	{
		fprintf(stderr, "L%i: division by zero\n", line_number);
		_ex(stack, NULL);
	}
	second->n = second->n % first->n;
	free(first);
	second->prev = NULL;
	*stack = second;
}
/**
  *f_pchar - function
  *@stack: stack
  *@line_number: line number
  *Return: nothing
  */
void f_pchar(stack_t **stack, unsigned int line_number)
{
	int num;

	if (!*stack)
	{
		fprintf(stderr, "L%i: can't pchar, stack empty\n", line_number);
		_ex(stack, NULL);
	}
	num = (*stack)->n;
	if ((num < 0) || (num > 255))
	{
		fprintf(stderr, "L%i: can't pchar, value out of range", line_number);
		_ex(stack, NULL);
	}
	printf("%c\n", num);
}
