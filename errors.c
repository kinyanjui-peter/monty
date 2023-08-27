#include "monty.h"

/**
 * reportUsageError - prints a usage error message
 * Return: FAILURE
 */
void reportusageerror(void)
{
    fprintf(stderr, "USAGE: monty file\n");
    exit(EXIT_FAILURE);
}

/**
 * reportopenerror - prints an error message when opening a file fails
 * @filename: the name of the file
 * Return: FAILURE
 */
void reportopenerror(char *filename)
{
    fprintf(stderr, "Error: Can't open file %s\n", filename);
    exit(EXIT_FAILURE);
}

/**
 * reportpusherror - handles an error during push operation
 * @fd: file descriptor
 * @lineBuffer: buffer
 * @stack: stack or queue
 * @lineNumber: line number of the command
 */
void reportpusherror(FILE *fd, char *lineBuffer, stack_t *stack, int lineNumber)
{
    fprintf(stderr, "L%u: usage: push integer\n", lineNumber);
    fclose(fd);
    free(lineBuffer);
    _free(stack);
    exit(EXIT_FAILURE);
}

/**
 * reportinstructionerror - Error handler for unknown instructions
 * @fd: file descriptor
 * @lineBuffer: buffer
 * @stack: stack or queue
 * @instruction: unknown instruction
 * @lineNumber: line number of the command
 */
void reportinstructionerror(FILE *fd, char *lineBuffer, stack_t *stack, char *instruction, int lineNumber)
{
    fprintf(stderr, "L%u: unknown instruction %s\n", lineNumber, instruction);
    fclose(fd);
    free(lineBuffer);
    _free(stack);
    exit(EXIT_FAILURE);
}

