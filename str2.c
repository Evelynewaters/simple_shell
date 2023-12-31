#include "shell.h"
/**
 * _strcmp - ===============
 * @s1: =============
 * @s2: ==============
 * Return: ==========
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);

	else
		return (*s1 < *s2 ? -1 : 1);
}
/**
 * _strcpy - =======
 * @dest: =========
 * @src: ===
 * Return: ========
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return  (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _strdup - =============
 * @str: =============
 * Return: ============
 */
char *_strdup(char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 * _strncmp - ====
 * @s1: -=--=
 * @s2: ======
 * @n: =======
 * Return: ==='
 */
int _strncmp(char *s1, char *s2, size_t n)
{

	if (s1 == NULL || s2 == NULL)
		return (-1);
	while (*s1 && *s2 && n > 0)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	else if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}
