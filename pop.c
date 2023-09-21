#include "monty.h"

/**
 * _pop - it removes an element from the top
 * @head: pointer to top of stack
 * @count: keeps count of the line numbers
 * Return: nothing
 */

void _pop(stack_t **head, unsigned int count)
{
	stack_t *pointer;

	if (*head)
	{
		pointer = *head;
		*head = pointer->next;

		if (pointer->next)
			pointer->next->prev = NULL;
		free(pointer);
	}

	fprintf(stderr, "L%d: can't pop an empty stack\n", count);
	free(bus.content);
	free_stack(*head);
	fclose(bus.file);
	exit(EXIT_FAILURE);
}
