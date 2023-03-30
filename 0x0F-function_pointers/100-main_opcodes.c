#include <stdio.h>
#include <stdlib.h>

/**
 * main - print first n opcodes
 * @argc: argument count
 * @argv: argument(s)
 *
 * Return: 0 on Success
 */
int main(int argc, char **argv)
{
	int n_bytes, i = 0;

	/* check argument count */
	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	/* check if num is negative */
	if (atoi(argv[1]) < 0)
	{
		printf("Error\n");
		exit(2);
	}

	unsigned char *cptr = (unsigned char *)main;

	/* increment ptr through main, printing first n_byte mem addresses */
	while (i < atoi(argv[1]))
	{
		printf("%02x", cptr[i]);
		if (i + 1 != atoi(argv[1]))
			putchar(' ');
		i++;
	}
	printf("\n");

	return (0);
}
