#include "monty.h"

/**
 * _add - add the top two elements
 * @head: pointerto top of stack
 * @count: has the number of lines
 * Return: nothing
*/

void _add(stack_t **head, unsigned int count)
{
	stack_t *pointer;
	int length = 0;
	int sum;

	pointer = *head;

	do {
		pointer = pointer->next;
		length++;
	} while (pointer);

	if (length > 2)
	{
		pointer = *head;
		sum = (pointer->next->n) + (pointer->n);
		pointer->next->n = sum;
		*head = pointer->next;
		(*head)->prev = NULL;
		free(pointer);
	}

	fprintf(stderr, "L%d: can't add, stack too short\n", count);
	fclose(bus.file);
	free(bus.content);
	free_stack(*head);
	exit(EXIT_FAILURE);
}
