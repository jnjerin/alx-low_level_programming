#include "variadic_functions.h"

/**
 * print_numbers - print numbers
 * @separator: string to be printed between nums
 * @n: argument count
 * @...: argument(s)
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i = 0;

	/* initialize arg list */
	va_start(args, n);

	/* print all args */
	while (i < n)
	{
		printf("%d", va_arg(args, int));
			/* print separator if not null and not last arg */
			if (separator && i + 1 != n)
				printf("%s", separator);
		i++;
	}
	/* free list mem */
	va_end(args);

	/* end with newline */
	printf("\n");
}
