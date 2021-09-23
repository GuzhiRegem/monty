#include "monty.h"

void free_s(stack_t **stack)
{
        stack_t *ptr;

        ptr = *stack;
        while (ptr)
        {
                free(ptr);
                ptr = ptr->next;
        }
}
instruction_t found_f(char *str)
{
        int i;
        instruction_t comms[] =
        {
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
void _ex(stack_t **stack, char *str)
{
	if (str)
		fprintf(stderr, "%s", str);
	free_s(stack);
	exit(EXIT_FAILURE);
}
int is_num(char *str)
{
	int i, found;

	found = 1;
	for (i = 0; str[i]; i++)
		if (!(str[i] >= '0' && str[i] <= '9'))
			found = 0;
	return (found);
}
