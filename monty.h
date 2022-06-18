#ifndef MAIN_H
#define MAIN_H


#define _POSIX_C_SOURCE  200809L
#define _GNU_SOURCE

extern int val = 0;
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack/ queue
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list for stack and queues
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/** push and pop functions **/
void push(stack_t **head, unsigned int line);
void pop(stack_t **head, unsigned int line);

/** print functions **/
void pint(stack_t **head, unsigned int line);
void pall(stack_t **head, unsigned int line);

/** handle opcode and execute **/
void execute(char *input, stack_t **head, unsigned int line);
#endif
