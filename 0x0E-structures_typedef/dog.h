#ifndef HOLBERTON_H
#define HOLBERTON_H

/**
 * struct dog - attributes of dog
 * @name: name of dog (string)
 * @age: age of dog (float)
 * @owner: owner of dog (string)
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

typedef struct dog dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);

#endif
