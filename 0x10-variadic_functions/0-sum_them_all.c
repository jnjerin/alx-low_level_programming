#include "variadic_functions.h"

/**
 * sum_them_all - add all arguments
 * @n: argument count
 * @...: argument(s)
 *
 * Return: sum on Success, 0 if n == 0
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list args;
	unsigned int i = 0;
	int sum = 0;

	/* initialize arg list */
	va_start(args, n);

	/* if no args, return 0 */
	if (!n)
		return (0);

	/* add args to sum */
	while (i < n)
	{
		sum += va_arg(args, int);
		i++;
	}
	/* free arg list */
	va_end(args);

	return (sum);
}
