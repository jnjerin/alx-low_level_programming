#include "holberton.h"

/**
 * factorial - return factorial of given number
 * @n: given number
 *
 * Return: factorial on Success, -1 on Error
 */
int factorial(int n)
{
	if (n < 0)
		return (-1);
	else if (n <= 1)
		return (1);
	else
		return (n * factorial(n - 1));
}
