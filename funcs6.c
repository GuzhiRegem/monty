#include "monty.h"
/**
  *f_stack - function
  *@stack: stack
  *@line_number: line number
  *Return: nothing
  */
void f_stack(stack_t **stack, unsigned int line_number)
{
	printf("stack: %p l_num: %i", (void *)stack, line_number);
}
/**
  *f_queue - function
  *@stack: stack
  *@line_number: line number
  *Return: nothing
  */
void f_queue(stack_t **stack, unsigned int line_number)
{
	printf("stack: %p l_num: %i", (void *)stack, line_number);
}
