#include "monty.h"

/**
 * _add - Adds the value of the top two nodes and
 * removes the top node
 * @stack: head of the linked list
 * @line_number: line of command
 * Return: void
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void) line_number;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", global()->cmd_num);
		exit(EXIT_FAILURE);
	}

	temp->next->n = temp->next->n + temp->n;
	_pop(&(*stack), 1);
}

/**
 * _sub - Substracts the top two elements of the stack from the second
 * top element of the stack
 * @stack: head of the linked list
 * @line_number: line of command
 * Return: void
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void) line_number;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", global()->cmd_num);
		exit(EXIT_FAILURE);
	}

	temp->next->n = temp->n - temp->next->n;
	_pop(&(*stack), 1);
}

/**
 * _mul - Mul the value of the top two nodes and
 * removes the top node
 * @stack: head of the linked list
 * @line_number: line of command
 * Return: void
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void) line_number;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", global()->cmd_num);
		exit(EXIT_FAILURE);
	}

	temp->next->n = temp->next->n * temp->n;
	_pop(&(*stack), 1);
}

/**
 * _div - Adds the value of the top two nodes and
 * removes the top node
 * @stack: head of the linked list
 * @line_number: line of command
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void) line_number;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", global()->cmd_num);
		exit(EXIT_FAILURE);
	}
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", global()->cmd_num);
		exit(EXIT_FAILURE);
	}
	temp->next->n = temp->next->n / temp->n;
	_pop(&(*stack), 1);
}

/**
 * _mod - Adds the value of the top two nodes and
 * removes the top node
 * @stack: head of the linked list
 * @line_number: line of command
 * Return: void
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void) line_number;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", global()->cmd_num);
		exit(EXIT_FAILURE);
	}
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", global()->cmd_num);
		exit(EXIT_FAILURE);
	}
	temp->next->n = temp->next->n % temp->n;
	_pop(&(*stack), 1);
}
