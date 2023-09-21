#include "monty.h"

/**
 * _push - add element to top of stack
 * @head: pointer to top of stack
 * @count: line no
 * Return: nothing
*/

void _push(stack_t **head, unsigned int count)
{
	stack_t *new_elem;
	int num = 0;
	(void)count;
	new_elem = malloc(sizeof(stack_t)); /*this might be an issue*/

	if (bus.arg == NULL)
	{
		fprintf(stderr, "L%d: ussage: push integer\n", num);
		exit(EXIT_FAILURE);
	}

	num = atoi(bus.arg);

	if (new_elem == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_elem->n = num;
	new_elem->prev = NULL;
	new_elem->next = *head;

	if (*head != NULL)
		(*head)->prev = new_elem;

	*head = new_elem;
}
