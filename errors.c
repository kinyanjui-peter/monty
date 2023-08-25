#include "monty.h"
/**
 * usage_error - prints an usage error message
 * Return: FAILURE
 */

void usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);

}
/**
 * instruction_error - Error handler for unknown instructions
 * @fd: file descriptor
 * @line: buffer
 * @stack:  stack or queue
 * @line_n: line number of the command
 * @val: instruction
 */
void instruction_error(FILE *fd, char *line, stack_t *stack, char *val, int line_n)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_n, val);
	fclose(fd);
	free(line);
	freestack(stack);
	exit(EXIT_FAILURE);
}

/**
 * push_error - handles a push error
 * @fd: file desciptor
 * @line: buffer
 * @stack:  stack or queue
 * @line_number: line number of the command
 */

void push_error(FILE *fd, char *line, stack_t *stack, int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	fclose(fd);
	free(line);
	freestack(stack);
	exit(EXIT_FAILURE);
}

