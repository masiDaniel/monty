#include "monty.h"

/**
 * _swap - swaps the top 2 elements against each other
 * @head: pointer to top of stack
 * @count: has the numeber of lines
 * Return: Nothing
 */

void _swap(stack_t **head, unsigned int count)
{
	stack_t *pointer;
	int temporary;
	int length = 0;

	pointer = *head;

	do {
		pointer = pointer->next;
		length++;
	} while (pointer);

	if (length > 2)
	{
		pointer = *head;
		temporary = pointer->n;
		pointer->n = pointer->next->n;
		pointer->next->n = temporary;

	}

	fprintf(stderr, "L%d: can't swap, stack too short\n", count);
	free(bus.content);
	free_stack(*head);
	fclose(bus.file);
	exit(EXIT_FAILURE);
}
