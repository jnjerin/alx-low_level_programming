#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>

void print_str(char *str)
{
	printf("%s\n", str);
}

/**
 * _isdigit - checks if characters is digit
 * @c: character to be checked
 *
 * Return: 1 on Success, 0 on Fail
 */
int _isdigit(char *str)
{
	int i;
	
	for (i = 0; str[i] != '\0'; i++)
		if (str[i] < '0' || str[i] > '9')
			return (0);
	return (1);
}

int str_len(char *str)
{
	int i;

	/* take str length */
	for (i = 0; str[i] != '\0'; i++)
		;
	return(i);
}

char *add_str(char *result, char *buffer, int i)
{
	int result_len = str_len(result);
	int k, j, sum = 0, carry = 0;

	char *new_result;
	
	printf("In add: result = \"%s\", buffer = \"%s\"\n", result, buffer);
	/* allocate mem for sum str & null-byte */
	new_result = malloc(sizeof(char) * (result_len + 1));
	if (new_result == NULL)
		return (NULL);

	/* adjust for place count */
	for (j = 0; j < i; j++)
		new_result[j] = result[j];
	
	for (k = 0; buffer[k] != '\0'; k++)
	{
		/* add digits */
		sum = (result[k + j] - '0') + (buffer[k] - '0');
		/* write sum to new result */
		new_result[k + j] = ((sum % 10) + carry) + '0';
		/* calculate carry */
		carry = sum / 10;

		if (buffer[k + 1] == '\0')
		{
			printf("carry = %d\n", carry);
			if (carry != 0)
			{
				new_result[k + j + 1] = ((result[k + 1] - '0') + carry) + '0';
				new_result[k + j + 2] = '\0';
			}
			else
				new_result[k + j + 1] = '\0';
		}
	}
	printf("new_result = \"%s\"\n", new_result);
	/* return sum */
	return (new_result);
}

char *mul_str(char *num1, char *num2)
{
	int prod, carry = 0;
	int i, j, k, place_cnt = 0;
	int num1_len = str_len(num1);
	int num2_len = str_len(num2);

	char *result, *buffer;

	/* allocate for combined length of nums plus null-byte */
	result = malloc(sizeof(char) * (num1_len + num2_len + 1));
	if (result == NULL || result == NULL)
		return (NULL);

	/* initialize result */
	for (k = 0; k < num1_len + num2_len; k++)
		result[k] = '0';
	
	buffer = malloc(sizeof(char) * (num1_len + num2_len + 1));
	if (buffer == NULL || result == NULL)
		return(NULL);

	printf("Entering mul_str:\nnum1 = %s\nnum2 = %s\n", num1, num2);

	for (i = num1_len - 1; i >= 0; i--, place_cnt++) /* loop through num1 */
	{
		carry = k = 0;
		for (j = num2_len - 1; j >= 0; j--, k++) /* loop through num2 */
		{
			/* multiply converted chars */
			printf("num1[%d] = %c, num2[%d] = %c\n", i, num1[i], j, num2[j]);
			prod = (num1[i] - '0') * (num2[j] - '0');
			printf("prod = %d\n", prod);
			/* grab remainder for digit */
			buffer[k] = ((prod % 10) + carry) + '0';
			printf("buffer[%d] = %c\n", k, buffer[k]);
			/* calculate carry */
			carry = prod / 10;
			/* check for/add final carry */
			if (j == 0)
			{
				if (carry != 0)
				{
					buffer[k + 1] = carry + '0';
					buffer[k + 2] = '\0';
				}
				else
					buffer[k + 1] = '\0';
			}
			printf("buffer = %s\n", buffer);
		}
		/* add buffer to result */
		result = add_str(result, buffer, place_cnt);
	}
	/* return product of multiplication */
	return (result);
}

/**
 * main - multiply two pos numbers
 * @argc: argument count
 * @argv: argument(s)
 */
int main(int argc,char **argv)
{
	char *num1 = argv[1];
	char *num2 = argv[2];
	char *product;

	/* check arg count */
	if (argc != 3)
	{
		printf("Error = argc not 3\n");
		exit(98);
	}

	/* check for non-digit */
	if (!(_isdigit(num1) && _isdigit(num2)))
	{
		printf("Error = non-digits present\n");
		exit(98);
	}

	/* multiply number */
	product = mul_str(num1, num2);

	/* print product string */
	print_str(product);

	return (0);
}
