#include "holberton.h"

/**
 * more_numbers - print 0 to 14 ten times
 */
void more_numbers(void)
{
	int i = 0;
	int j;

	while (i <= 9)
	{
		j = 0;
		while (j <= 14)
		{
			if (j / 10 != 0)
				_putchar((j / 10) + '0');

			_putchar((j % 10) + '0');
			j++;
		}
		_putchar('\n');
		i++;
	}
}
