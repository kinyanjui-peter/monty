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
	stack_t *top = *stack;
	int temp = 0;

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
/**
 * sub - subtracts the top two elements of the stack.
 * @stack: double pointer to the head of the stack
 * @line_number: the line number
 */

void sub(stack_t **stack, unsigned int line_number)
{
    stack_t *second_element = NULL;
    int difference = 0;

    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
        _free(*stack);
        exit(EXIT_FAILURE);
    }
    second_element = (*stack)->next;
    difference = second_element->n;
    difference -= (*stack)->n;
    pop(stack, line_number);
    second_element->n = difference;
}
/**
 * pchar - adds the top two elements of the stack.
 * @stack: double pointer to the head of stack
 * @line_number: the line number
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n >= 0 && (*stack)->n <= 127)
		printf("%c\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		_free(*stack);
		exit(EXIT_FAILURE);
	}

}
/**
 * add - adds the top two elements of the stack.
 * @stack: double pointer to the head of the stack
 * @line_number: the line number
 */

void add(stack_t **stack, unsigned int line_number)
{
    stack_t *temp_stack = NULL;
    int result = 0;

    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        _free(*stack);
        exit(EXIT_FAILURE);
    }
    temp_stack = (*stack)->next;
    result = (*stack)->n;
    result += (*stack)->next->n;
    pop(stack, line_number);
    temp_stack->n = result;
}
