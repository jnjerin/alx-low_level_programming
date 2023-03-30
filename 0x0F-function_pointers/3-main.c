#include "3-calc.h"

/**
 * main - perform calculater operations
 * @argc: number of arguments
 * @argv: argument(s)
 *
 * Return: 0 on Success
 */
int main(int argc, char **argv)
{
	int num1, num2;
	int (*f)(int, int);

	char *op = argv[2];

	/* check for correct arg number */
	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	/* convert args to ints */
	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);

	/* check for zero division */
	if ((*op == '/' || *op == '%') && (num2 == 0))
	{
		printf("Error\n");
		exit(100);
	}

	/* select operation */
	f = get_op_func(op);

	if (f == NULL)
	{
		printf("Error\n");
		exit(99);
	}

	/* print result */
	printf("%d\n", f(num1, num2));

	return (0);
}
