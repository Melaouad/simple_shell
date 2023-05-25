#include "shell.h"

/**
 * parse_line - Parses a line into an array of tokens.
 * @line: The input line to be parsed.
 *
 * Return: An array of strings (tokens) extracted from the line.
 *
 * Description: This function takes a line of input and tokenizes it
 * into an array of strings. It uses strtok() to split the line based
 * on delimiters (spaces, tabs, carriage returns, newlines, and bells).
 * The tokens are stored in dynamically allocated memory, and the array
 * is terminated with a NULL pointer.
 */
char **parse_line(char *line)
{
	int position = 0;
	char **tokens = malloc(MAX_ARG_SIZE * sizeof(char *));
	char *token;

	token = strtok(line, " \t\r\n\a");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= MAX_ARG_SIZE)
		{
			fprintf(stderr, "shell: too many arguments\n");
			exit(EXIT_FAILURE);
		}

		token = strtok(NULL, " \t\r\n\a");
	}
	tokens[position] = NULL;
	return (tokens);
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
			alpha_beta(args);
			exit(EXIT_SUCCESS);
		}
		else
		{
			wait(NULL);
		}

		free(args);
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
