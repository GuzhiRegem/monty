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
	printf("stack: %p l_num: %i", (void *)stack, line_number);
}
/**
  *f_div - function
  *@stack: stack
  *@line_number: line number
  *Return: nothing
  */
void f_div(stack_t **stack, unsigned int line_number)
{
	printf("stack: %p l_num: %i", (void *)stack, line_number);
}
