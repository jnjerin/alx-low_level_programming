#include <stdlib.h>
#include <stdio.h>
#include "dog.h"

/**
 * print_dog - print contents of struct dog
 * @d: struct to print
 */
void print_dog(struct dog *d)
{
	/* check if pointer to struct is null */
	if (d != NULL)
	{
		/* print name */
		if (d->name == NULL)
			printf("Name: (nil)\n");
		else
			printf("Name: %s\n", d->name);

		/* print age */
		printf("Age: %.6f\n", d->age);

		/* print owner */
		if (d->owner == NULL)
			printf("Owner: (nil)\n");
		else
			printf("Owner: %s\n", d->owner);
	}
}
