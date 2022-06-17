#include "monty.h"

/**
 * main - entry to monty
 * @argc: argc counter
 * @argv: array of arguments
 *
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	FILE *fp = NULL;
	char *buffer = NULL, *str = NULL;
	size_t s = 0;
	unsigned int line = 1;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (!fp)
	{
		dprintf(STDERR_FILENO, "Error: Can't open this file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&buffer, &s, fp) != -1)
	{
		if (*buffer != '\n')
		{
			str = strtok(buffer, "\n");
			execute(str, &stack, line);
		}
		line++;
	}
	fclose(fp);
	free(buffer);
	if (stack != NULL)
		while (stack != NULL)
			pop(&stack, line);
	return (0);
}
