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
void f_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first = NULL, *second = NULL, *third = NULL;

	first = *stack;
	if (first)
		second = first->next;
	if (!first || !second)
		fprintf(stderr, "L%i: can't swap, stack too short\n", line_number);
	third = second->next;
	first->prev = second;
	first->next = third;
	second->prev = NULL;
	second->next = first;
	*stack = second;
}
/**
  *f_add - function
  *@stack: stack
  *@line_number: line number
  *Return: nothing
  */
void f_add(stack_t **stack, unsigned int line_number)
{
	printf("stack: %p l_num: %i", (void *)stack, line_number);
}
