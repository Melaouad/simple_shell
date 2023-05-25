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
 * is terminated with a NULL pointer. If there are too many arguments,
 * it prints an error message using fprintf() and exits with a failure status.
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
			fprintf(stderr, "%s: too many arguments\n", tokens[0]);
			exit(EXIT_FAILURE);
		}

		token = strtok(NULL, " \t\r\n\a");
	}
	tokens[position] = NULL;
	return (tokens);
}
