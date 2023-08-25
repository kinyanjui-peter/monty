#include "monty.h"
/**
 * free_stack - Free all and close file
 * @stack: Stack
 */

void freestack(stack_t **stack)
{
    stack_t *tmp;

    while (*stack)
    {
        tmp = *stack;
        *stack = (*stack)->next;
        free(tmp);
    }

    if (cmd.fd != NULL)
    {
        fclose(cmd.fd);
    }

    if (cmd.line != NULL)
    {
        free(cmd.line);
    }
}

/**
 * _free - free stack
 * @stack: stack
 */

void _free(stack_t *stack)
{
stack_t *list = NULL;

	list = stack;

	if (list != NULL)
	{
		_free(list->next);
		free(list);
	}
}
