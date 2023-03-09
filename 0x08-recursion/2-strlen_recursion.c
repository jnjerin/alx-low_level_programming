#include "holberton.h"

/**
 * _strlen_recursion - returns length of string
 * @s: string to count
 *
 * Return: length of string
 */
int _strlen_recursion(char *s)
{
	if (*s)
		return (1 + _strlen_recursion(s + 1));
	else
		return (0);
}
