#include "monty.h"

int main_value;

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

