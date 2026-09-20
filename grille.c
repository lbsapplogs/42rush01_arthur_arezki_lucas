#include "skyscraper.h"

/*
*initializes the grid to all zeros, representing an empty grid.
*modifies the grid in place, so no return value is needed.
*/
void	init_grid(int grid[4][4])
{
	int	r;
	int	c;

	r = 0;
	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			grid[r][c] = 0;
			c++;
		}
		r++;
	}
}

/*
** prints the grid to the standard output, with each number separated by a space.
** 
*/
void	print_grid(int grid[4][4])
{
	int		r;
	int		c;
	char	digit;

	r = 0;
	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			digit = grid[r][c] + '0';
			write(1, &digit, 1);
			if (c < 3)
				write(1, " ", 1);
			c++;
		}
		write(1, "\n", 1);
		r++;
	}
}
