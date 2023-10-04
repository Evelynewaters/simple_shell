#include "shell.h"
/**
 * str_len - function counts the num chars of a string
 *
 * @str: pointer to null terminated string to be counted
 *
 * Return: numbers of characters counted
 */

int str_len(char *str)
{
	if (*str == '\0' || str == NULL)
		return (0);
	return (1 + str_len(++str));
}

/**
 * free_all - free
 * @arr: free all
 *
 */
void free_all(char **arr)
{
	int i = 0;

	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
