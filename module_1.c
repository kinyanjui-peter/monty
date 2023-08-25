#include "monty.h"

int value;

/**
 * createNode - creates a new node
 * @n: the value of the node
 * Return: new node
 */

stack_t *createNode(int n)
{
    stack_t *new_node = NULL;

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->n = n;
    new_node->next = NULL;
    new_node->prev = NULL;

    return (new_node);
}

/** push - pushes a new node with the given value to the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number where the operation occurs (not used in this case)
 * @value: value to be pushed onto the stack
 */

void push(stack_t **stack, unsigned int line_number, int value)
{
    stack_t *new = NULL;
    (void)line_number;

    new = createNode(value);

    new->next = *stack;
    if (*stack != NULL)
        (*stack)->prev = new;
    *stack = new;
}

#include "monty.h"

/**
 * pop - removes the top element of the stack.
 * @stack: double pointer to the head of the stack
 * @line_number: the current line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *new_top;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		_free(*stack);
		exit(EXIT_FAILURE);
	}

	else
	{
		new_top = (*stack)->next;
		free(*stack);
		if (new_top)
			new_top->prev = NULL;
		*stack = new_top;
	}
}

