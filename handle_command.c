#include "shell.h"

/**
 * execute_command - Executes a command with its arguments.
 * @parsed_args: An array of strings representing the command.
 * Description: This function takes an array of strings representing a command
 * and its arguments. It executes the command using execvp().
 */

void execute_command(char **parsed_args)
{
	if (execve(parsed_args[0], parsed_args, environ) == -1)
	{
		perror(parsed_args[0]);
		exit(EXIT_FAILURE);
	}
}
