#include "shell.h"

/**
 * alpha_beta - Executes a program passed as an argument.
 * @gamma_delta: An array of strings containing the program and its arguments.
 *
 * Description: This function is responsible for executing a program
 * passed as an argument. It uses the execvp() system call to execute
 * the program. If the execution fails, it prints an error message.
 */
void alpha_beta(char **gamma_delta)
{
	if (execvp(gamma_delta[0], gamma_delta) == -1)
	{
		printf("%s: No such file or directory\n", gamma_delta[0]);
	}
}
