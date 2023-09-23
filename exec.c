#include "monty.h"

/**
 * execute - this function executes the opcodes
 * @stack: pointer to header of teh stack
 * @count: counts th elines
 * @file: pointer to file that has the opcodes
 * @content: this is the data
 * Return: (0) success (1) failure
*/

int execute(stack_t **stack, unsigned int count, FILE *file, char *content)
{
	char *opcode;
	unsigned int x = 0;
	instruction_t instructions[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{NULL, NULL}
	};
	opcode = strtok(content, " \n\t");
	if (!opcode)
		return (0);

	bus.arg = strtok(NULL, " \n\t");

	for (x = 0; instructions[x].opcode; x++)
	{
		if (strcmp(opcode, instructions[x].opcode) == 0)
		{
			instructions[x].f(stack, count);
			return (0);
		}
	}
	fclose(file);
	free(content);
	free_stack(*stack);
	fprintf(stderr, "L%d: unknown instruction %s\n", count, opcode);
	exit(EXIT_FAILURE);
}
