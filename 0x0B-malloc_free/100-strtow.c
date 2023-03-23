#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

char **_cpy_strtow(char **words, char *str, int word_cnt);

/**
 * count_words - count words in string
 * @str: string to count
 *
 * Return: number of words in string
 */
int count_words(char *str)
{
	int i, word_cnt = 0;

	/* loop through string, count words */
	for (i = 0; str[i] != '\0'; i++)
		if ((i == 0 && str[i] != ' ') || (str[i - 1] == ' ' && str[i] != ' '))
			word_cnt++;
	return (word_cnt);
}

/**
 * strtow - split string into words
 * @str: string to split
 *
 * Return: pointer to array of seperated words, NULL on Fail
 */
char **strtow(char *str)
{
	char **words;
	int i, row, str_cnt, word_cnt = count_words(str);

	/* cover error cases */
	if (str == NULL || *str == '\0' || word_cnt == 0)
		return (NULL);

	/* allocate word memory, plus null pointer */
	words = malloc(sizeof(char *) * (word_cnt + 1));
	if (words == NULL)
		return (NULL);

	/* allocate letter memory */
	for (row = 0, str_cnt = 0; row < word_cnt; row++)
		for (; str[str_cnt] != '\0'; str_cnt++)
			if (str[str_cnt] != ' ')
			{
				/* take word length */
				for (i = 0; str[str_cnt + i] != ' ' && str[str_cnt + i] != '\0'; i++)
					;

				/* allocate for word, plus null-byte */
				*(words + row) = malloc(sizeof(char) * (i + 1));

				/* check for fail */
				if (*(words + row) == NULL)
				{
					for (; row > 0; row--)
						/* free previously allocated rows */
						free(*(words + (row - 1)));
					free(words);
					return (NULL);
				}

				/* increase str_cnt past newly malloc'ed word */
				str_cnt += i;
				/* once word is allocated break str loop to increment row */
				break;
			}
	return (_cpy_strtow(words, str, word_cnt));
}

/**
 * _cpy_strtow - copy words from string to 2D array
 * @words: 2D array of words
 * @str: string to parse
 * @word_cnt: number of words in str / number of rows in words
 *
 * Return: pointer to array of copied words
 */
char **_cpy_strtow(char **words, char *str, int word_cnt)
{
	int i, row, str_cnt;

	for (row = 0, str_cnt = 0; row < word_cnt; row++)
		for (; str[str_cnt] != '\0'; str_cnt++)
			if (str[str_cnt] != ' ')
			{
				/* copy words from str */
				for (i = 0; str[str_cnt + i] != ' ' && str[str_cnt + i] != '\0'; i++)
					words[row][i] = str[str_cnt + i];
				words[row][i] = '\0';

				/* increase str_cnt past copied word */
				str_cnt += i;
				break;
			}
	return (words);
}
