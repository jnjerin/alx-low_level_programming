#include "variadic_functions.h"

int valid_arg(char c);

/**
 * print_all - print anything
 * @format: format specifier
 */
void print_all(const char * const format, ...)
{
	va_list args;
	int j, i = 0;
	char *buffer;

	va_start(args, format);
	/* loop until null-byte */
	while (format && format[i])
	{
		/* print according to format specifier */
		switch (format[i])
		{
			case 'c':
				printf("%c", va_arg(args, int));
				break;
			case 'i':
				printf("%d", va_arg(args, int));
				break;
			case 'f':
				printf("%f", va_arg(args, double));
				break;
			case 's':
				buffer = va_arg(args, char *);
				if (buffer)
				{
					printf("%s", buffer);
					break;
				}
				printf("(nil)");
		}
		j = 1;
		while (valid_arg(format[i]) && format[i + j])
		{
			if (valid_arg(format[i + j]))
			{
				printf(", ");
				break;
			}
			j++;
		}
		i++;
	}
	/* free args */
	va_end(args);

	printf("\n");
}

/**
 * valid_arg - check if arg is valid
 * @c: arg type specifier
 *
 * Return: 1 if valid, 0 if not valid
 */
int valid_arg(char c)
{
	switch (c)
	{
		case 'c': case 'i': case 'f': case 's':
			return (1);
	}
	return (0);
}
