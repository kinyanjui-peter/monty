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
		freestack(stack);
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

stack_t *createnew_node(int n)
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
/**
 * push_monty - adds a new node with the given value to the stack
 * @stack: pointer to the head of the stack
 * @line_number: number to be pushed
 *
 */

void push_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *new;
	int i;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		set_tok_error(malloc_error());
		return;
	}

	if (op_toks[1] == NULL)
	{
		set_tok_error(no_int_error(line_number));
		return;
	}

	for (i = 0; op_toks[1][i]; i++)
	{
		if (op_toks[1][i] == '-' && i == 0)
			continue;
		if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
		{
			set_tok_error(no_int_error(line_number));
			return;
		}
	}
	new->n = atoi(op_toks[1]);

	if (check_mode(*stack) == STACK) /* STACK mode insert at front */
	{
		tmp = (*stack)->next;
		new->prev = *stack;
		new->next = tmp;
		if (tmp)
			tmp->prev = new;
		(*stack)->next = new;
	}
	else /* QUEUE mode insert at end */
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		new->next = NULL;
		tmp->next = new;
	}
}


/**
 * pall - Prints the values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void pall(stack_t **new_stack, unsigned int line_num) {
    stack_t *current_node = (*new_stack)->next;
    while (current_node)
    {
        printf("%d\n", current_node->n);
        current_node = current_node->next;
    }
    (void)line_num;
}

/** 
 * pop - removes top mostelement of the stack.
 * @stack: points to head of the stack
 * @line_number: the current line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		_free(*stack);
		exit(EXIT_FAILURE);
	}

	else
	{
		temp = (*stack)->next;
		free(*stack);
		if (temp)
			temp->prev = NULL;
		*stack = temp;
	}
}
