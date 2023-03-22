#include "holberton.h"
#include <stdio.h>

int convert_string(char *string);

/**
 * main - multiply two numbers
 * @argc: number of arguments
 * @argv: argument(s)
 *
 * Return: 0 on Success, 1 on Fail
 */
int main(int argc, char **argv)
{
	int num1 = 0, num2 = 0;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	num1 = convert_string(*(argv + 1));
	num2 = convert_string(*(argv + 2));

	printf("%d\n", num1 * num2);
	return (0);
}

/**
 * convert_string - convert string to int
 * @string: string to convert
 *
 * Return: integer result on Success
 */
int convert_string(char *string)
{
	int digit = 0, result = 0, cnt = 0, sign = 1;

	/* track sign */
	if (string[cnt] == '-')
	{
		sign = -1;
		cnt++;
	}

	while (string[cnt] != '\0')
	{
		/* convert ascii val to int */
		digit = string[cnt] - '0';
		/* times result up a place and add new digit */
		result = (result * 10) + digit;
		cnt++;
	}
	result *= sign;

	return (result);
}
