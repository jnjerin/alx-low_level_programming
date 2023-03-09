#include "holberton.h"

int prime_test(int n, int x);

/**
 * is_prime_number - checks if integer is prime number
 * @n: number to check
 *
 * Return: 1 if prime, 0 if not prime
 */
int is_prime_number(int n)
{
	int x = n - 1;

	if (n == 1)
		return (0);
	if (n <= 0)
		return (0);
	return (prime_test(n, x));
}

/**
 * prime_test - test if prime number
 * @n: number to check
 * @x: multiples to check with
 *
 * Return: 1 if prime, 0 if not prime
 */
int prime_test(int n, int x)
{
	if (x == 1)
		return (1);
	if (n % x == 0)
		return (0);
	else
		return (prime_test(n, x - 1));
}
