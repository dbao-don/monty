#include "monty.h"
/**
 * read_file - a function that reads files.
 * Return: Exit success
 */
int read_file(void)
{
	void (*f)(stack_t **stack, unsigned int line_number) = NULL;
	char *cmd;
	char *number;
	char line[MAX_LINE_LENGTH];

	while (fgets(line, sizeof(line), global()->file_pointer) != NULL)
	{
		global()->cmd_num++;
		if (strlen(line) == sizeof(line) - 1 && line[sizeof(line) - 2] != '\n')
		{
			fprintf(stderr, "Line too long\n");
			exit(EXIT_FAILURE);
		}
		if (line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = '\0';
		cmd = strtok(line, " \t\n");
		if (!cmd || strchr(line, '#') != NULL)
			continue;
		f = get_op(cmd);
		number = strtok(NULL, " \t\n");
		global()->node_number = number;
		f(&(global()->global_head), 1);
	}
	return (EXIT_SUCCESS);
}
