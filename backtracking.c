#include "skyscraper.h"

// check if a number is already present in the row or column
static int	is_safe(int grid[4][4], int r, int c, int maxh)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[r][i] == maxh || grid[i][c] == maxh)
			return (0);
		i++;
	}
	return (1);
}

// count the number of visible skyscrapers from a given line (row or column)
static int	check_view(int *line)
{
	int	i;
	int	current_max;
	int	visible_count;

	i = 0;
	current_max = 0;
	visible_count = 0;
	while (i < 4)
	{
		if (line[i] > current_max)
		{
			current_max = line[i];
			visible_count++;
		}
		i++;
	}
	return (visible_count);
}

// validate the entire grid against the clues (num_input)
static int	is_grid_valid(int grid[4][4], int *num_input)
{
	int	r;
	int	c;
	int	temp[4];

	// 1. Validation des colonnes (colUp et colDown)
	c = 0;
	while (c < 4)
	{
		r = -1;
		while (++r < 4) temp[r] = grid[r][c];
		if (check_view(temp) != num_input[c]) return (0);
		r = -1;
		while (++r < 4) temp[r] = grid[3 - r][c];
		if (check_view(temp) != num_input[4 + c]) return (0);
		c++;
	}
	// 2. Validation des lignes (rowLeft et rowRight)
	r = 0;
	while (r < 4)
	{
		c = -1;
		while (++c < 4) temp[c] = grid[r][c];
		if (check_view(temp) != num_input[8 + r]) return (0);
		c = -1;
		while (++c < 4) temp[c] = grid[r][3 - c];
		if (check_view(temp) != num_input[12 + r]) return (0);
		r++;
	}
	return (1);
}

// Algorithme de backtracking avec la nouvelle nomenclature
int	solve_skyscraper(int grid[4][4], int *num_input, int r, int c)
{
	int	maxh;

	if (r == 4)
		return (is_grid_valid(grid, num_input));
	if (c == 4)
		return (solve_skyscraper(grid, num_input, r + 1, 0));
	maxh = 1;
	while (maxh <= 4)
	{
		if (is_safe(grid, r, c, maxh))
		{
			grid[r][c] = maxh;
			if (solve_skyscraper(grid, num_input, r, c + 1))
				return (1);
			grid[r][c] = 0;
		}
		maxh++;
	}
	return (0);
}

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
