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
