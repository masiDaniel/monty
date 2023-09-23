#include "monty.h"

/**
* _mod - calculates the modular
* @head: pointer to top of stack
* @count: keeps the number of lines
* Return: Nothing
*/

void _mod(stack_t **head, unsigned int count)
{
	int modular;
	int length = 0;
	stack_t *pointer;

	pointer = *head;
	do {
		pointer = pointer->next;
		length++;
	} while (pointer);

	if (length < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", count);
		free(bus.content);
		free_stack(*head);
		fclose(bus.file);
		exit(EXIT_FAILURE);
	}

	pointer = *head;

	if (pointer->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", count);
		fclose(bus.file);
		free_stack(*head);
		free(bus.content);
		exit(EXIT_FAILURE);
	}

	modular = (pointer->next->n) % (pointer->n);
	pointer->next->n = modular;
	*head = pointer->next;
	if (*head)
		(*head)->prev = NULL;

	free(pointer);
}
