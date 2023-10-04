#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"
#include <errno.h>

#define MAX_COMMAND_LENGTH 100

/**
 * main - This program allows users to enter commands interactively
 * @argc: number of arg
 * @argv: array of arg
 * Return: 0
 */
int main(int argc, char *argv[]);
int main(int argc, char *argv[])
{
	static char command[MAX_COMMAND_LENGTH];
	int i = 1;
	char *args[1000] = {NULL};
	char *token = NULL;
	int arg_count = 0;
	char **arr = NULL;
	int k = 0;
	/*(void)argv;*/
	/*(void)argc;*/

	if (argc > 1)
	{
		arr = executeCommandsFromFile(argv[1]);
		/*printf("%s\n", arr[1]);*/
		if (arr != NULL)
		{
			k = 0;
			while (arr[k] != NULL)
			{
				i = executeCommand(arr[k]);
				if (i == 0)
				{
					if (arr)
						free_all(arr);
					exit(0);
					break;
				}
				k++;
			}
			k = 0;
			arg_count = 0;
			free_all(arr);
		}
	}
	else
	{

		/*display_prompt();*/
		while (read_command(command, sizeof(command)))
		{
			token = strtok(command, ";\n");
			while (token != NULL)
			{
				if (token[0] == '#')
				{
					args[arg_count++] = NULL;
					break;
				}
				args[arg_count++] = token;
				token = strtok(NULL, ";\n");
			}
			args[arg_count] = NULL;
			if (*args != NULL)
			{
				k = 0;
				while (args[k])
				{
					i = executeCommand(args[k]);
					if (i == 0)
					{
						exit(0);
						break;
					}
					k++;
				}
				k = 0;
				arg_count = 0;
				*args = NULL;
			}
			else
			{
				i = executeCommand(command);
				if (i == 0)
				{
					exit(0);
					break;
				}
			}
		}
	}
	return (0);
}
