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
