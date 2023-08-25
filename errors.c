#include "mionty.h"
void handle_errors(char *message, unsigned int line_number, ...)
{
    va_list args;
    va_start(args, line_number);
    fprintf(stderr, "Error: ");
    vfprintf(stderr, message, args);
    fprintf(stderr, "\n");
    va_end(args);
    exit(EXIT_FAILURE);
}

