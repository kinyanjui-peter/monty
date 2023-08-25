#include "monty.h"
/**
 * sub - subtracts the top two elements of the stack.
 * @stack: pointer to the head of the stack
 * @line_number: the line number
 */
void sub(stack_t **stack, unsigned int line_number)
{
    stack_t *val = NULL;
    int diff = 0;

    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
        _free(*stack);
	exit(EXIT_FAILURE);
    }
    val = (*stack)->next;
    diff = val->n;
    diff -= (*stack)->n;
    pop(stack, line_number);
    val->n = diff;
}
