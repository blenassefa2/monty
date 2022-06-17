#include "main.h"

/**
 * pop - pops from stack
 * @head: pointer to head of stack
 * @line: input bytecode line number
 */

void pop(stack_t **head, unsigned int line)
{
	if (head == NULL || *head == NULL)/*if stack is empty*/
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}
	if ((*head)->next != NULL)
	{
		*head = (*head)->next;
		free((*head)->prev);
		(*head)->prev = NULL;
	}
	else
	{
		free(*head);
		*head = NULL;
	}
}

/**
 * push - push an element to the stack
 * @head: head pointer
 * @line: input bytecode line number
 * @val: data to push
 */
void push(stack_t **head, unsigned int line)
{
	stack_t *new;

	if (head == NULL)
	{
		printf("L%u: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		while (head)
			pop(head, line);
		exit(EXIT_FAILURE);
	}
	new->n = val;
	new->prev = NULL;
	new->next = *head;

	if (*head != NULL)
		(*head)->prev = new;
	*head = new;
}
/**
 * pall - prints all stack elements starting from top
 * @head: pointer to stack
 */
void pall(stack_t **head, unsigned int line)
{
	stack_t *temp = *head;

	while (temp)
	{
		printf("%d\n", line - line + temp->n);
		temp = temp->next;
	}
}

/**
 * pint - prints stack element at the top
 * @head: pointer to stack
 * @line: input bytecode line number
 */
void pint(stack_t **head, unsigned int line)
{
	if (!*head)
	{
		printf("L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
