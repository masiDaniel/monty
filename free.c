#include "monty.h"

/**
 * free_stack - free a stack
 * @stack: pointer to top of the stack to be freed
 * Return: nothing
*/

void free_stack(stack_t *stack)
{
	stack_t *temporary;

	if (stack == NULL)
		return;
	do {
		temporary = stack;
		stack = stack->next;
		free(temporary);
	} while (stack);

}
