#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE_SIZE 1024
#define MAX_ARG_SIZE 64
#define RAND_PROMPT "#cisfun$ "

void execute_command(char **parsed_args);
char **parse_line(char *line);

#endif
