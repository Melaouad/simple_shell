#include "shell.h"
#include <sys/types.h>
#include <sys/wait.h>

/**
 * interactive_mode - Implements the interactive mode of the shell.
 * Description: This function implements the interactive mode of the shell.
 */
void interactive_mode(void)
{
	char line[MAX_LINE_SIZE];
	char **args;

	while (1)
	{
		printf(RAND_PROMPT);

		if (fgets(line, sizeof(line), stdin) == NULL)
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}

		line[strcspn(line, "\n")] = '\0';
		args = parse_line(line);

		if (fork() == 0)
		{
			execute_command(args);
		}
		else
		{
			wait(NULL);
		}

		free(args);
	}
}

/**
 * noninteractive_mode - Implements the non-interactive mode of the shell.
 * @argv: Command line arguments.
 * Description: This function implements the non-interactive mode of the shell.
 */
void noninteractive_mode(char **argv)
{
	char **args = parse_line(argv[1]);

	if (fork() == 0)
	{
		execute_command(args);
	}
	else
	{
		wait(NULL);
	}

	free(args);
}

/**
 * main - Entry point of the shell program.
 * @argc: Number of command line arguments.
 * @argv: Array of command line arguments.
 * Description: This is the entry point of the shell program
 * Return: 0 on success, 1 on error.
 */
int main(int argc, char **argv)
{
	if (argc == 1)
	{
		interactive_mode();
	}
	else if (argc == 2)
	{
		noninteractive_mode(argv);
	}
	else
	{
		fprintf(stderr, "%s: too many arguments\n", argv[0]);
		return (1);
	}

	return (0);
}
