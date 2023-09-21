#include "monty.h"

/**
 * _pint - print value at top of stack
 * @head: pointer to top of stack
 * @count: has teh number of lines
 * Return: Nothing
 */

void _pint(stack_t **head, unsigned int count)
{
	if (*head)
	{
		printf("%d\n", (*head)->n);
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		exit(EXIT_FAILURE);
	}
}
