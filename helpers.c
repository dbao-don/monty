#include "monty.h"

/**
 * global - a function that gets the global variable.
 * Return: global variable
 */
global_t *global(void)
{
	static global_t global = {
		NULL,
		NULL,
		NULL,
		0,
		0,
	};

	return (&global);
}

/**
 * check_num - checks if string is a valid number
 * @string: input
 * Return: 1 if true, -1 if false
 */
int check_num(char *string)
{
	char c;
	int minusCount = 0;

	if (string == NULL || *string == '\0')
		return (-1);

	while (*string)
	{
		c = *string;
		switch (c)
		{
			case '-':
				if (++minusCount > 1)
					return (-1);
				break;
			default:
				if (c < '0' || c > '9')
					return (-1);
		}
		string++;
	}
	return (1);
}

/**
 * free_linkedlist - a function that frees a linked list.
 * @head: pointer to head node
 * Return: Nothing
 */
void free_linkedlist(stack_t *head)
{
	stack_t *free_node = head;
	stack_t *temp;

	if (head)
	{
		while (free_node)
		{
			temp = free_node->next;
			free(free_node);
			free_node = temp;
		}
	}
}
