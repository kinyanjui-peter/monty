#include "monty.h"

/**
 * nop - function name
 * @stack: head pointer of the list
 * @line_number: current line number
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * swap - swaps the top two elements of the stack.
 * @stack: double pointer to the head of the list
 * @line_number: line number
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;  // Renamed 'val' to 'top'
	int temp = 0;  // Renamed 'tmp' to 'temp'

	if (top == NULL || top->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		_free(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = top->n;
		top->n = top->next->n;
		top->next->n = temp;
	}
}
