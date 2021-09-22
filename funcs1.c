#include "monty.h"

void f_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	line_number = line_number;
	new = malloc(sizeof(stack_t));
	if (!new)
		return;
	new->next = *stack;
	new->prev = NULL;
	*stack = new;
}
void f_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = *stack;

	if (stack != NULL || *stack != NULL)
        {
                line_number = line_number;
                while (new_node != NULL)
                {
                        printf("%i\n", new_node->n);
                new_node = new_node->next;
                }
        }
}
void f_pint(stack_t **stack, unsigned int line_number)
{
	line_number = line_number;
	printf("%i\n", (*stack)->n);
}
