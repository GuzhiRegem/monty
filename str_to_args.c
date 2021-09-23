#include "monty.h"

/**
 *str_to_arguments - makes an array of strings from a string
 *@buffer: string to separate
 *@sep: separator
 *Return: array of strings
 */
char **str_to_arguments(char *buffer, char sep)
{
	char **out;
	int i, i2, i3, error = 0, arg_amount = 1, offs;
	char *ptr, *tmp;

	for (offs = 0; buffer[offs] == sep; offs++)
		;
	for (i = offs; buffer[i]; i++)
		if (buffer[i] == sep)
			if (buffer[i + 1] && (buffer[i + 1] != sep))
				arg_amount++;
	out = malloc((arg_amount + 1) * sizeof(char *));
	if (!out)
		return (out);
	out[arg_amount] = NULL;
	ptr = buffer + offs;
	for (i = 0; i < arg_amount; i++)
	{
		while (ptr[0] == sep)
			ptr = ptr + 1;
		for (i2 = 0; ptr[i2] && (ptr[i2] != sep); i2++)
			;
		tmp = malloc(i2 + 1);
		tmp[i2] = 0;
		if (!tmp)
		{
			error = 1;
			break;
		}
		for (i3 = 0; i3 < i2; i3++)
			tmp[i3] = ptr[i3];
		ptr += i2;
		out[i] = tmp;
	}
	if (error)
	{
		for (i2 = 0; i2 < i; i2++)
			free(out[i2]);
		free(out);
	}
	return (out);
}
void free_args(char **args)
{
	int i;

	for (i = 0; args[i]; i++)
		free(args[i]);
	free(args);
}
