#include "holberton.h"
/**
 * print_number - print integer
 * @n: number to print
 */
void print_number(int n)
{
	int zero_switch = 0;

	(n < 0) ? _putchar('-') : (n *= -1);
	if ((n / 1000000000) % 10 != 0)
		zero_switch = 1;
	if (zero_switch == 1)
		_putchar(-(n / 1000000000) % 10 + '0');
	if ((n / 100000000) % 10 != 0)
		zero_switch = 1;
	if (zero_switch == 1)
		_putchar(-(n / 100000000) % 10 + '0');
	if ((n / 10000000) % 10 != 0)
		zero_switch = 1;
	if (zero_switch == 1)
		_putchar(-(n / 10000000) % 10 + '0');
	if ((n / 1000000) % 10 != 0)
		zero_switch = 1;
	if (zero_switch == 1)
		_putchar(-(n / 1000000) % 10 + '0');
	if ((n / 100000) % 10 != 0)
		zero_switch = 1;
	if (zero_switch == 1)
		_putchar(-(n / 100000) % 10 + '0');
	if ((n / 10000) % 10 != 0)
		zero_switch = 1;
	if (zero_switch == 1)
		_putchar(-(n / 10000) % 10 + '0');
	if ((n / 1000) % 10 != 0)
		zero_switch = 1;
	if (zero_switch == 1)
		_putchar(-(n / 1000) % 10 + '0');
	if ((n / 100) % 10 != 0)
		zero_switch = 1;
	if (zero_switch == 1)
		_putchar(-(n / 100) % 10 + '0');
	if ((n / 10) % 10 != 0)
		zero_switch = 1;
	if (zero_switch == 1)
		_putchar(-(n / 10) % 10 + '0');
	_putchar((n % 10) * -1 + '0');
}
