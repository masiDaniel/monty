#include <stdio.h>
#include "monty.h"

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
	int no_chars;
	size_t input = 0;

	if (stream == NULL || lineptr == NULL || n == NULL)
		return (-1);
	if (*lineptr == NULL)
	{
		*n = 130;
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
		(*lineptr)[input++] = (char)no_chars;
		if (no_chars == '\n')
			break;
	} while ((no_chars = fgetc(stream)) != EOF);

	(*lineptr)[input] = '\0';
	if (no_chars == EOF && input == 0)
	{
		free(*lineptr);
		*lineptr = NULL;
		return (-1);
	}
	return (input);
}
