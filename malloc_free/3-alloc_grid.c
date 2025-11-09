#include <stdlib.h>

/**
 * alloc_grid - allocate a 2D grid of ints and initialize to 0
 * @width: number of columns
 * @height: number of rows
 *
 * Return: pointer to grid (height x width) on success, or NULL on failure
 */
int **alloc_grid(int width, int height)
{
	int **grid;
	int r, c;

	if (width <= 0 || height <= 0)
		return (NULL);

	grid = (int **)malloc(height * sizeof(int *));
	if (grid == NULL)
		return (NULL);

	for (r = 0; r < height; r++)
	{
		grid[r] = (int *)malloc(width * sizeof(int));
		if (grid[r] == NULL)
		{
			/* free any rows already allocated, then the grid */
			while (r > 0)
			{
				r--;
				free(grid[r]);
			}
			free(grid);
			return (NULL);
		}

		for (c = 0; c < width; c++)
			grid[r][c] = 0;
	}

	return (grid);
}

