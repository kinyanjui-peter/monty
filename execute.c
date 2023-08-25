#include "monty.h"

/* Define a structure to hold the command information */
cmd_t command = {NULL, NULL};

/**
 * Execute - Read the file and execute the Monty bytecode
 * @filename: Name of the file to be executed
 */
void Execute(char *filename)
{
    int currentLine = 0, result = 0;
    size_t bufferSize = 0;
    char *token = NULL, *value = NULL;
    stack_t *stack = NULL;

    /* Open the file for reading */
    command.fileDescriptor = fopen(filename, "r");
    if (command.fileDescriptor)
    {
        while (getline(&command.line, &bufferSize, command.fileDescriptor) != -1)
        {
            currentLine++;
            token = strtok(command.line, " \n\t\r");
            if (token == NULL)
            {
                free(token);
                continue;
            }
            else if (*token == '#')
                continue;
            value = strtok(NULL, " \n\t\r");
            result = get_opc(&stack, token, value, currentLine);
            if (result == 1) /* GetOpcodeAndValue returns 1 when the value is not a digit */
                push_error(command.fileDescriptor, command.line, stack, currentLine); /* Print push error */
            else if (result == -1) /* GetOpcodeAndValue returns -1 if the instruction is not recognized */
                instruction_error(command.fileDescriptor, command.line, stack, token, currentLine); /* Print instruction error */
        }
        free(command.line);
        freestack(stack);
        fclose(command.fileDescriptor);
    }
