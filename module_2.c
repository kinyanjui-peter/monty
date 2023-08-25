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
/**
 * pchar - adds the top two elements of the stack.
 * @stack: pointer to the head of stack
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
        _free(*stack); // Assuming _free is defined in a different file
        exit(EXIT_FAILURE);
    }
}
/**
 * add - adds the top two elements of the stack.
 * @stack: pointer to the head of the stack
 * @line_number: the line number
 */
void add(stack_t **stack, unsigned int line_number)
{
    stack_t *val = NULL;
    int sum = 0;

    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        _free(*stack); // Assuming _free is defined in a different file
        exit(EXIT_FAILURE);
    }
    val = (*stack)->next;
    sum = (*stack)->n;
    sum += (*stack)->next->n;
    pop(stack, line_number); // Assuming pop is defined in a different file
    val->n = sum;
}
/**
 * swap - swaps the top two elements of the stack.
 * @stack: double pointer to the head of the list
 * @line_number: line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
    stack_t *val;
    int tmp = 0;

    val = *stack;
    if (val == NULL || val->next == NULL)
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        _free(*stack); // Assuming _free is defined in a different file
        exit(EXIT_FAILURE);
    }
    else
    {
        tmp = val->n;
        val->n = val->next->n;
        val->next->n = tmp;
    }
}
