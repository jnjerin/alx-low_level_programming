#include "holberton.h"

/**
 * _isdigit - checks if characters is digit
 * @c: character to be checked
 *
 * Return: 1 on Success, 0 on Fail
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
