#include "rush.h"

int	counting_visible_from_left(int row[4])
{
	int	count;
	int	maxh;
	int	c;

	count = 0;
	maxh = 0;
	c = 0;
	while (c < 4)
	{
		if (row[c] > maxh)
		{
			maxh = row[c];
			count++;
		}
		c++;
	}
	return (count);
}

int	counting_visible_from_right(int row[4])
{
	int	count;
	int	maxh;
	int	c;

	count = 0;
	maxh = 0;
	c = 3;
	while (c >= 0)
	{
		if (row[c] > maxh)
		{
			maxh = row[c];
			count++;
		}
		c--;
	}
	return (count);
}

int	counting_visible_from_top(int grid[4][4], int c)
{
	int	count;
	int	maxh;
	int	r;

	count = 0;
	maxh = 0;
	r = 0;
	while (r < 4)
	{
		if (grid[r][c] > maxh)
		{
			maxh = grid[r][c];
			count++;
		}
		r++;
	}
	return (count);
}

int	counting_visible_from_bottom(int grid[4][4], int c)
{
	int	count;
	int	maxh;
	int	r;

	count = 0;
	maxh = 0;
	r = 3;
	while (r >= 0)
	{
		if (grid[r][c] > maxh)
		{
			maxh = grid[r][c];
			count++;
		}
		r--;
	}
	return (count);
}

/*
** Vérification finale selon l'ordre standard du sujet de la Piscine :
** clues[0..3]   = colUp    (Top)
** clues[4..7]   = colDown  (Bottom)
** clues[8..11]  = rowLeft  (Left)
** clues[12..15] = rowRight (Right)
*/
int	check_visibility(int grid[4][4], int *clues)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (counting_visible_from_top(grid, i) != clues[i])
			return (0);
		if (counting_visible_from_bottom(grid, i) != clues[i + 4])
			return (0);
		if (counting_visible_from_left(grid[i]) != clues[i + 8])
			return (0);
		if (counting_visible_from_right(grid[i]) != clues[i + 12])
			return (0);
		i++;
	}
	return (1);
}
