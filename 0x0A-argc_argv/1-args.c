#include "holberton.h"
#include <stdio.h>

/**
 * main - print argc
 * @argc: number of arguments
 * @argv: optional argument
 * @__attribute__((unused): keyword to denote optional arg
 * Return: 0 on Success
 */
int main(int argc, char **argv __attribute__((unused)))
{
	printf("%d\n", --argc);

	return (0);
}
