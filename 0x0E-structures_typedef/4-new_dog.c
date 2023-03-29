#include <stdlib.h>
#include "dog.h"

int str_len(char *s);

/**
 * new_dog - create new dog
 * @name: name of dog (char)
 * @age: age of dog (float)
 * @owner: owner of dog (char)
 *
 * Return: new dog on Success, NULL on Fail
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_dog;
	int i;

	/* allocate for new struct */
	new_dog = malloc(sizeof(struct dog));
	if (new_dog == NULL)
		return (NULL);

	/* allocate for name and null-byte */
	new_dog->name = malloc(sizeof(*name) * (str_len(name) + 1));
	if (new_dog->name == NULL)
	{
		free(new_dog);
		return (NULL);
	}

	/* allocate for owner and null-byte */
	new_dog->owner = malloc(sizeof(*owner) * (str_len(owner) + 1));
	if (new_dog->owner == NULL)
	{
		free(new_dog);
		free(new_dog->name);
		return (NULL);
	}
	/* copy name to new struct */
	for (i = 0; name[i] != '\0'; i++)
		new_dog->name[i] = name[i];
	new_dog->name[i] = '\0';

	/* copy owner to new struct */
	for (i = 0; owner[i] != '\0'; i++)
		new_dog->owner[i] = owner[i];
	new_dog->owner[i] = '\0';

	/* initialize age */
	new_dog->age = age;

	/* return */
	return (new_dog);
}

/**
 * str_len - find string length
 * @s: string to count
 *
 * Return: length of string
 */
int str_len(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}
