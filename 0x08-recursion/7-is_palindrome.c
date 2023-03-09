#include "holberton.h"

int cmpchar(char *s, int l_char, int length);
int _strlen_recursion(char *s);

/**
 * is_palindrome - check if string is palindrome
 * @s: string to check
 *
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome(char *s)
{
	int length, l_char;

	/* check for empty string */
	if (!*s)
		return (1);

	/* find length and set leftmost char */
	length = l_char = _strlen_recursion(s) - 1;

	return (cmpchar(s, l_char, length));
}

/**
 * cmpchar - compare strings
 * @s: original string
 * @l_char: left margin
 * @length: length of string
 *
 * Return: 1 if palindrome, 0 if not
 */
int cmpchar(char *s, int l_char, int length)
{
	if (!*s)
		return (1);
	if (l_char == (length / 2) - 1)
		return (1);
	if (*s == *(s + l_char))
	{
		return (cmpchar(s + 1, l_char - 2, length));
	}
	else
		return (0);
}
/**
 * _strlen_recursion - returns length of string
 * @s: string to count
 *
 * Return: length of string on success, 0 on fail
 */
int _strlen_recursion(char *s)
{
	if (*s)
		return (1 + _strlen_recursion(s + 1));
	else
		return (0);
}
