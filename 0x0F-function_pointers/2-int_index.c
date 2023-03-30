#include "function_pointers.h"

/**
 * int_index - search for number in array
 * @array: array to search
 * @size: size of array
 * @cmp: pointer to comparison function
 *
 * Return: index number of positive comparison, -1 on Fail
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i = 0;

	if (cmp && array)
		if (size > 0)
			while (i++ < size)
				if (cmp(array[i]))
					return (i);
	return (-1);
}
