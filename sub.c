#include "monty.h"

/**
 * _sub - subtract top element from second top in stack
 * @head: pointer to top of stack
 * @count: has teh number of lines
 * Return: nothing
 */

void _sub(stack_t **head, unsigned int count)
{
	int result;
	int length = 0;
	stack_t *ptr;

	ptr = *head;
	do {
		ptr = ptr->next;
		length++;
	} while (ptr);

	if (length < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", count);
		free_stack(*head);
		fclose(bus.file);
		free(bus.content);
		exit(EXIT_FAILURE);
	}

	ptr = *head;
	result = (ptr->next->n) - (ptr->n);
	ptr->next->n = result;
	*head = ptr->next;
	(*head)->prev = NULL;
	free(ptr);
}
