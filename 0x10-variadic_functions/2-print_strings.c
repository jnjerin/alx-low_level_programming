#include "variadic_functions.h"

/**
 * print_strings - print strings
 * @separator: string to separate strings
 * @n: argument count
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	char *buffer;
	unsigned int i = 0;

	/* initialize arg list */
	va_start(args, n);

	while (i < n)
	{
		/* extract current arg to buffer string */
		buffer = va_arg(args, char *);

		/* print s if not NULL */
		if (buffer)
			printf("%s", buffer);
		else
			printf("(nil)");
		/* print separator if not NULL for all but last arg */
		if (separator && i + 1 != n)
			printf("%s", separator);

		i++;
	}

	/* free arg list */
	va_end(args);

	/* print newline */
	printf("\n");
}
