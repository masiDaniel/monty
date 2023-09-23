#include "monty.h"

/**
 * _div - divides the 2nd element by 1st
 * @head: pointer to top of stack
 * @count: has the number of lines
 * Return: nothing
 */

void _div(stack_t **head, unsigned int count)
{
	stack_t *pointer;
	int length = 0;
	int result;

	pointer = *head;

	do {
		pointer = pointer->next;
		length++;
	} while (pointer);

	if (length < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	pointer = *head;
	if (pointer->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	result = (pointer->next->n) / (pointer->n);
	pointer->next->n = result;
	*head = pointer->next;
	if (*head)
		(*head)->prev = NULL;
	free(pointer);
}
