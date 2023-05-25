#include "shell.h"

/**
 * alpha_beta - Executes a program passed as an argument.
 * @gamma_delta: The program to execute.
 *
 * Description: This function is responsible for executing a program
 * passed as an argument. It uses the execve() system call to execute
 * the program. If the execution fails, it prints an error message.
 */
void alpha_beta(char *gamma_delta)
{
	char *epsilon_zeta[2] = {NULL, NULL};

	epsilon_zeta[0] = gamma_delta;

	if (execve(gamma_delta, epsilon_zeta, NULL) == -1)
	{
		printf("%s: No such file or directory\n", gamma_delta);
	}
}

/**
 * eta_theta - Implements the main loop of the shell.
 *
 * Description: This function implements the main loop of the shell.
 * It continuously prompts the user for input, reads the input, and
 * executes the corresponding program using the alpha_beta() function.
 * The loop continues until the user decides to exit.
 */
void eta_theta(void)
{
	char iota_kappa[MAX_LINE_SIZE];

	while (1)
	{
		printf(RAND_PROMPT);

		if (fgets(iota_kappa, sizeof(iota_kappa), stdin) == NULL)
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}

		iota_kappa[strcspn(iota_kappa, "\n")] = '\0';

		if (fork() == 0)
		{
			alpha_beta(iota_kappa);
			exit(EXIT_SUCCESS);
		}
		else
		{
			wait(NULL);
		}
	}
}

/**
 * main - Entry point of the shell program.
 *
 * Description: This is the entry point of the shell program. It calls
 * the eta_theta() function to start the main loop of the shell. The
 * program will keep running until the user decides to exit.
 *
 * Return: Always returns 0.
 */
int main(void)
{
	eta_theta();
	return (0);
}
