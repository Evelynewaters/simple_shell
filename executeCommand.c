#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"
#include <errno.h>
/**
 * executeCommand - exe interpretation
 * command: command
 */
#define MAX_COMMAND_LENGTH 100000
int executeCommand(const char *command);
int executeCommand(const char *command)
{
	int pid;
	char *args[MAX_COMMAND_LENGTH];
	int arg_count = 0;
	int exit_status;

	char *token = strtok((char *)command, " \"\'\t\r\n");

	while (token != NULL && arg_count < MAX_COMMAND_LENGTH - 1)
	{
		if (token[0] == '#')
		{
			args[arg_count++] = NULL;
			break;
		}
		args[arg_count++] = token;
		token = strtok(NULL, " \"\'\t\r\n");
	}
	args[arg_count] = NULL;
	if (args[0] == NULL)
	{
		return (1);
	}
	if (_strcmp(args[0], "exit") == 0)
	{
		if (args[1] != NULL)/*./hsh: 1: exit: Illegal number: HBTN*/
		{
			if (atoi(args[1]) <= 0)
			{
				write(2, "./hsh: 1: exit: Illegal number: ",
						strlen("./hsh: 1: exit: Illegal number: "));
				write(2, args[1], strlen(args[1]));
				write(2, "\n", 1);
				exit(2);
			}
			else
			{
				exit(atoi(args[1]));
			}
		}
		exit(0);
	}
	if (_strcmp(args[0], "env") == 0)
	{
		perform_env(environ);
		return (1);
	}
	if (_strcmp(args[0], "printenv") == 0)
	{
		perform_env(environ);
		return (1);
	}
	pid  = fork();

	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			/*perror("./hsh");*/
			exit(2);
		}
	}
	else if (pid < 0)
	{
		exit(2);
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			exit_status = WEXITSTATUS(status);
			if (exit_status  != 0 && !isatty(STDIN_FILENO))
			{
				exit(exit_status);
			}
		}
	}

	return (1);
}
