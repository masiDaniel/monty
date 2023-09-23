#include <stdio.h>
#include "monty.h"
#include <stdbool.h>

/**
 * _getline - reads a whole line from the standard input
 * @lineptr: pointer to line being read
 * @n: length of the line deing read
 * @stream: file being read from
 * Return: pointer to input
*/

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	char *test;
	int current_char;
	size_t input = 0;

	if (stream == NULL || lineptr == NULL || n == NULL)
		return (-1);
	if (*lineptr == NULL)
	{
		*n = 128;
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}

	do {
		if (input >= (*n - 1))
		{
			*n *= 2;
			test = (char *)realloc(*lineptr, *n);
			if (test == NULL)
				return (-1);
			*lineptr = test;
		}
		current_char = fgetc(stream);
		if (current_char == EOF || current_char == '\n')
			break;
		(*lineptr)[input++] = (char)current_char;
	} while (1);

	(*lineptr)[input] = '\0';
	if (current_char == EOF && input == 0)
	{
		free(*lineptr);
		*lineptr = NULL;
		return (-1);
	}
	return (input);
}
