#include "monty.h"
/**
  *f_pstr - function
  *@stack: stack
  *@line_number: line number
  *Return: nothing
  */
void f_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;
	int num;

	line_number = line_number;
	ptr = *stack;
	while (ptr)
	{
		num = ptr->n;
		if ((num <= 0) || (num > 126))
			break;
		printf("%c", num);
		ptr = ptr->next;
	}
	printf("\n");
}
/**
  *f_rotl - function
  *@stack: stack
  *@line_number: line number
  *Return: nothing
  */
void f_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *last;

	line_number = line_number;
	first = *stack;
	if (!first)
		return;
	last = first;
	while (last->next)
		last = last->next;
	last->next = first;
	*stack = first->next;
	first->next = NULL;
	first->prev = last;
	(*stack)->prev = NULL;
}
/**
  *f_rotr - function
  *@stack: stack
  *@line_number: line number
  *Return: nothing
  */
void f_rotr(stack_t **stack, unsigned int line_number)
{
	line_number = line_number;
	stack = stack;
}
