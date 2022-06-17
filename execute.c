#include "main.h"

int val = 0;
/**
 * check_digit - checks if imput is digit
 * @val: input
 *
 * Return: 1 if number, 0 otherwise
 */
int check_digit(char *val)
{
	if (!val)
		return (0);
	if (*val == '-')
		val++;
	while (*val != '\0')
	{
		if (!isdigit(*val))
			return (0);
		val++;
	}

	return (1);
}

/**
 * execute - deals with line argument and executes
 * @input: string argument to execute
 * @stack: double pointer to stack
 * @line: line of the argument
 */
void execute(char *input, stack_t **stack, unsigned int line)
{
	char *token = NULL;
	instruction_t operations[] = {
		{"push", push}, {"pop", pop}, {"pall", pall}, {"pint", pint}
	};
	int value;

	token = strtok(input, " ");
	if (!token || *token == '\n' || *token == '#' || *token == ' ')
		return;

	for (value = 0; value < 4; value++)
	{
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, " ");
			if (check_digit(token) == 0)
			{
				printf("L%d: usage: push integer\n", line);
				if (stack != NULL)
					while (stack != NULL)
						pop(stack, line);
				exit(EXIT_FAILURE);
			}
			val = atoi(token);
			operations[0].f(stack, line);
			break;
		}
		if (strcmp(token, operations[value].opcode) == 0)
		{
			operations[value].f(stack, line);
			break;
		}
		if (value == 3)
		{
			printf("L%d: unknown instruction %s\n", line, token);
			if (stack)
				while (stack)
					pop(stack, line);
			exit(EXIT_FAILURE);
		}
	}
}
