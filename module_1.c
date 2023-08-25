#include "monty.h"
void push(stack_t **stack, int value)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node) {
        handle_errors("Error: malloc failed", 0);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack) {
        (*stack)->prev = new_node;
    }

    *stack = new_node;
}

void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;
    while (current) {
        printf("%d\n", current->n);
        current = current->next;
    }
    (void)line_number;
}

