#include "monty.h"
void execute_instruction(instruction_t *instructions, char *opcode, unsigned int line_number){
    int i = 0;
    while (instructions[i].opcode) {
        if (strcmp(opcode, instructions[i].opcode) == 0) {
            instructions[i].f(&stack, line_number);
            return;
        }
        i++;
    }
    handle_errors("L%d: unknown instruction %s", line_number, opcode);
}

