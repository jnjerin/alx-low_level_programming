#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * free_grid - free 2D grid
 * @grid: grid to free
 * @height: height of grid
 */
void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
		free(*(grid + i));
	free(grid);
}
