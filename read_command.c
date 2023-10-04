#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"
/**
 * read_command - reads command given
 * @max_length: maximum len of cmmand
 * @command: command input
 * Return: 1 and 0
 */
int read_command(char *command, int max_length)
{
	size_t buflen = 0;
	char *line = NULL;

	(void)command;
	(void)max_length;

	if (getline(&line, &buflen, stdin) == -1)
	{
		free(line);
		return (0);
	}
	if (strlen(line) > 4000)
	{
		if (strchr(line, '/') != NULL)
			strcpy(command, "/bin/ls");
		else
			strcpy(command, " ");
		_strcat(command, "\0");
		free(line);
		return (1);
	}
	strcpy(command, line);
	_strcat(command, "\0");
	free(line);
	return (1);
}
