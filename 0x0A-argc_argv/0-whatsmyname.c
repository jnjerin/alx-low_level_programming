#include "holberton.h"
#include <stdio.h>

/**
 * main - print program name
 * @argc: number of arguments
 * @argv: arguments (string)
 *
 * Return: 0 on Success
 */
int main(int argc, char **argv)
{
	if (argc)
	{
		argc--;
		printf("%s\n", argv[argc]);
	}

	return (0);
}
