#include "holberton.h"
#include <stdio.h>

int subcmp(char *s1, char *s2, int i);

/**
 * wildcmp - compare two strings
 * @s1: string to be compared
 * @s2: string to compare to
 *
 * Return: 1 if identical, 0 if differing
 */
int wildcmp(char *s1, char *s2)
{
	/* if s1 and s2 are both at '\0' return 1 */
	if (!*s1 && !*s2)
		return (1);
	/* if s1 is equal to s2 proceed thru both */
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));
	/* if s1 and s2 are not equal */
	else if (*s1 != *s2)
	{
		/* if s1 is not s2 but s2 is '*' */
		if (*s2 == '*')
		{
			/* if s2 is followed by another '*' proceed thru s2 */
			if (*(s2 + 1) == '*')
				return (wildcmp(s1, s2 + 1));
			else if (*(s2 + 1) == '\0' && *s1 == '\0')
				return (1);
			/* if s2 is not followed by '*' proceed from next s1 that matches s2 + 1 */
			else
			{
				return (wildcmp(s1 + subcmp(s1, s2, (_strlen_recursion(s1) - 1)), s2 + 1));
			}
		}
		return (0);
	}
	return (1);
}

/**
 * subcmp - compare s1 to char proceeding '!' in s1
 * @s1: string to compare
 * @s2: string to compare to
 * @i: counter
 *
 * Return: i on Success, 0 on Fail
 */
int subcmp(char *s1, char *s2, int i)
{
	if (*(s1 + i) == *(s2 + 1))
		return (i);
	else if (*(s1 + i) == '\0')
		return (0);
	else
		return (subcmp(s1, s2, i - 1));
}

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
