#ifndef MONTY_H
#define MONTY_H

typedef struct stack_s {
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

typedef struct instruction_s {
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

stack_t *stack = NULL;  // The stack is initially empty

// Function prototypes
void push(stack_t **stack, int value);
void pall(stack_t **stack, unsigned int line_number);
void execute_instruction(instruction_t *instructions, char *opcode, unsigned int line_number);
void handle_errors(char *message, unsigned int line_number);
#endif
