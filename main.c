#include <stdio.h>
#include "monty.h"

/**
 * main - deriver code
 * @argc: arg no
 * @argv: arg vector
 * Return: (1) fail or (0) success
*/


int main(int argc, char **argv)
{
	bus_t bus = {NULL, NULL, NULL};
	char *content = NULL;
	unsigned int no = 1;
	size_t size = 0;
	ssize_t read = 1;
	stack_t *stack = NULL;
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	bus.file = file;
	while (read > 0)
	{
		if (content)
		{
			free(content);
			content = NULL;
		}
		read = _getline(&content, &size, file);
		bus.content = content;
		if (read < 0)
		{
			free(content);
			break;
		}
		execute(&stack, no, file, content);
		no++;
	}
	free_stack(stack);
	fclose(file);
	return (0);
}
