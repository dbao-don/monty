#include "monty.h"

/**
 * _push - creates new node at the top of the stack
 * @stack: head of the linked list
 * @line_number: line of command
 * Return: void
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	stack_t *current = *stack;
	(void) line_number;

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (!global()->node_number || check_num(global()->node_number) == -1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", global()->cmd_num);
		free(new_node);
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(global()->node_number);
	new_node->prev = NULL;
	if (current)
	{
		new_node->next = current;
		current->prev = new_node;
	}
	global()->global_head = new_node;
}

/**
 * _pall - Prints all the values on the stack,
 * starting from the top of the stack
 * @stack: head of the linked list
 * @line_number: line of command
 * Return: void
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_node = *stack;
	(void) line_number;

	while (temp_node)
	{
		printf("%d\n", temp_node->n);
		temp_node = temp_node->next;
	}
}

/**
 * _pint - Prints the value at the top of the stack.
 * @stack: head of the linked list
 * @line_number: line of command
 * Return: void
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void) line_number;

	if (!temp)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", global()->cmd_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", temp->n);
}

/**
 * _pop - creates new node at the top of the stack
 * @stack: head of the linked list
 * @line_number: line of command
 * Return: void
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current_node = *stack;
	(void) line_number;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", global()->cmd_num);
		exit(EXIT_FAILURE);
	}

	*stack = current_node->next;
	if (current_node->next != NULL)
		current_node->next->prev = NULL;
	free(current_node);
}

/**
 * _swap - swaps the top of the stack with the node before
 * @stack: head of the linked list
 * @line_number: line of command
 * Return: void
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_node = *stack;
	(void) line_number;

	if (!temp_node || !temp_node->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", global()->cmd_num);
		exit(EXIT_FAILURE);
	}

	*stack = temp_node->next;
	if ((*stack)->next != NULL)
	{
		(*stack)->next->prev = temp_node;
		temp_node->next = (*stack)->next;
		temp_node->prev = *stack;
		(*stack)->next = temp_node;
		(*stack)->prev = NULL;
	}
}
