#include "monty.h"

/**
 * _nop - doesn’t do anything.
 * @stack: head of the linked list
 * @line_number: line of command
 * Return: void
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 * _pchar - Prints the char value .
 * @stack: head of the linked list
 * @line_number: line of command
 * Return: void
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	(void) line_number;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", global()->cmd_num);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 177)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", global()->cmd_num);
		exit(EXIT_FAILURE);
	}
	else
		printf("%c\n", (*stack)->n);
}

/**
 * _pstr - Prints the string starting at the top of the stac,
 * @stack: head of the linked list
 * @line_number: line of command
 * Return: void
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_node = *stack;
	(void) line_number;

	while (temp_node->next)
	{
		if (temp_node->next == 0 || temp_node->n < 32 || temp_node->n > 177)
			break;

		printf("%c", temp_node->n);
		temp_node = temp_node->next;

	}
	printf("\n");
}

/**
 * _rotl - a function that reverses a linked list
 * @stack: head node
 * @line_number: line number
 * Return: void
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *end_node = *stack;
	int temp;
	(void) line_number;

	if (*stack)
	{
		temp = (*stack)->n;
		while (end_node->next)
		{
			end_node->n = end_node->next->n;
			end_node = end_node->next;
		}
		end_node->n = temp;
	}
}

/**
 * _rotr - a function that reverses a linked list
 * @stack: head node
 * @line_number: line number
 * Return: void
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *before = NULL;
	stack_t *next = NULL;
	(void) line_number;

	if (*stack)
	{
		while ((*stack) != NULL)
		{
			next = (*stack)->next;
			(*stack)->next = before;
			(*stack)->prev = next;
			before = (*stack);
			(*stack) = next;
		}
		*stack = before;
	}
}
