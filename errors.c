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

void instruction_error(FILE *fd, char *line, stack_t *stack, char *val, int line_n)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_n, val);
	fclose(fd);
	free(line);
	freestack(stack);
	exit(EXIT_FAILURE);
}
