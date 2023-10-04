#include "shell.h"
/**
 * perform_env - A function that handles environment
 * @env: double pointer to environment
 * This function prints the env variables.
 *
 * Return: 0, on sucess
 */
void perform_env(char **env)
{
	int p;

	for (p = 0; env[p] != NULL; p++)
	{
		write(STDOUT_FILENO, env[p], str_len(env[p]));
		write(STDOUT_FILENO, "\n", 1);

	}
}
