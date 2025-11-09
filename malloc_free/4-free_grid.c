#include <stdlib.h>

/**
 * free_grid - frees a 2D grid previously allocated by alloc_grid
 * @grid: pointer to the grid (array of int pointers)
 * @height: number of rows in the grid
 *
 * Return: void
 */
void free_grid(int **grid, int height)
{
	int r;

	if (grid == NULL || height <= 0)
		return;

	for (r = 0; r < height; r++)
		free(grid[r]);

	free(grid);
}

