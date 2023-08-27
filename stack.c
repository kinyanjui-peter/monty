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
        _free(current->next);
        free(current);
    }
}
/**
 * clean_stack_and_resources - Free stack and close files
 * @stack: Stack
 */

void clean_stack(stack_t **stack)
{
	stack_t *current = *stack;

	while (current)
	{
		stack_t *temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
	 (cmd.fd)
	 {
		 fclose(cmd.fd);
		 cmd.fd = NULL;
	 }
	 if (cmd.line)
	 {
		 free(cmd.line);
		 cmd.line = NULL;
	 }
}
