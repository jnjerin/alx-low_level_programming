#include "holberton.h"
#include <stdio.h>

/**
 * main - print all arguments
 * @argc: number of arguments
 * @argv: argument(s)
 *
 * Return: 0 on Success
 */
int main(int argc, char **argv)
{
	int i = 0;

	while (argc--)
		printf("%s\n", argv[i++]);
	return (0);
}
