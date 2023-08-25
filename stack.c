#include "monty.h"

/**
 * free_stack - free the stack
 * @stack: stack to be freed
 */

void _free(stack_t *stack)
{
    stack_t *current = NULL;

    current = stack;

    if (current != NULL)
    {
        free_stack(current->next);
        free(current);
    }
}
