#include "monty.h"

/**
 * destruct - free some global variables
 * Return: Void
 */
void destruct(void) __attribute__ ((destructor));
void destruct(void)
{
	if (global()->line_buf)
		free(global()->line_buf);
	if (global()->global_head)
		free_linkedlist(global()->global_head);
	if (global()->file_pointer)
		fclose(global()->file_pointer);
}
/**
 * main - entry point for monty program
 * @argc: argument count
 * @argv: arguments
 * Return: EXIT_SUCCESS on success, else an error code
 */
int main(int argc, char *argv[])
{
	if (argv[1])
		global()->file_pointer = fopen(argv[1], "r");

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (!(global()->file_pointer))
	{
		fprintf(stderr, "Error Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	read_file();
	return (EXIT_SUCCESS);
}
