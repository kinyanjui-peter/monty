#include "monty.h"

cmd_t cmd_data = {NULL, NULL};

/**
 * execute - reads the file and executes the monty byte
 * @argv: argument vector
 */

void execute(char *argv)
{
	int current_line = 0, result = 0;
	size_t buffer_size = 0;
	char *current_token = NULL, *current_value = NULL;
	stack_t *data_stack = NULL;

	cmd_data.fd = fopen(argv, "r");
	if (cmd_data.fd)
{
	while (getline(&cmd_data.line, &buffer_size, cmd_data.fd) != -1)
	{
		current_line++;
		current_token = strtok(cmd_data.line, " \n\t\r");
	if (current_token == NULL)
	{
		free(current_token);
		continue;
	}
	else if (*current_token == '#')
	continue;
	current_value = strtok(NULL, " \n\t\r");
	result = get_opc(&data_stack, current_token, current_value, current_line);
	if (result == 1) /* get_opt returns 1 when the value is not a digit */
		reportpusherror(cmd_data.fd, cmd_data.line,
				data_stack, current_line); /** print push error*/
	else if (result == -1) /* get_opt returns -1 if not the instruction */
		reportinstructionerror(cmd_data.fd, cmd_data.line,
				data_stack, current_token, current_line);
/* print instruction error */
	}
	free(cmd_data.line);
	_free(data_stack);
	fclose(cmd_data.fd);
	}
	else
	{
		reportopenerror(argv);
	}
}

