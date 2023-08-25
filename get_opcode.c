#include "monty.h"
/**
 * get_opc - gets the opcode function
 * @stack: pointer to the stack or queue
 * @arg: the command
 * @val: the value
 * @line_number: the line number
 * Return: 0 on success || 1 if not a digit || -1 on error
 */

int get_opc(stack_t **stack, char *arg, char *val, int line_number)
{
	int counter = 0;

	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"nop", nop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", divide},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{NULL, NULL}
	};

	while (op[counter].opcode)
	{
		if (!strcmp(arg, op[counter].opcode))
		{
			if (!strcmp(arg, "push"))
			{
				if (_isdigit(val) == 1)
					value = atoi(val);
				else
					return (1);/** if not digit*/
			}
			op[counter].f(stack, (unsigned int)line_number);
			break;
		}
		counter++;
	}
	if (!op[counter].opcode)
		return (-1);

	return (0);
}
