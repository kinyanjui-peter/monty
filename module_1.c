#include "monty.h"
/**
 * pint - prints the value at the top of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: the current line number
 */
int number;

void top_pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	else
		fprintf(stdout, "%d\n", (*stack)->n);
}

/**
 * createnew_node - creates a new node
 * @n: the value of the node
 * Return: new node
 */

stack_t *createnewnode(int n)
{
	stack_t *new = NULL;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = NULL;
	new->prev = NULL;

	return (new);
}
