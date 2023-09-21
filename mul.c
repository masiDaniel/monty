#include "monty.h"

/**
 * _mul - multiply top 2 elements
 * @head: pointer to top of stack
 * @count: has the number of lines
 * Return: nothing
 */

void _mul(stack_t **head, unsigned int count)
{
	int product;
	int length = 0;
	stack_t *pointer;

	pointer = *head;

	do {
		pointer = pointer->next;
		length++;
	} while (pointer);

	if (length > 2)
	{
		pointer = *head;
		product = (pointer->n) * (pointer->next->n);
		pointer->next->n = product;
		*head = pointer->next;
		(*head)->prev = NULL;
		free(pointer);
	}

	fprintf(stderr, "L%d: can't mul, stack too short\n", count);
	fclose(bus.file);
	free_stack(*head);
	free(bus.content);
	exit(EXIT_FAILURE);
}
