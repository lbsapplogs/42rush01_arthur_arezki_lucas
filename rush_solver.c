/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_solver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luborrer <luborrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 19:30:50 by luborrer          #+#    #+#             */
/*   Updated: 2026/09/20 19:30:50 by luborrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_place(int grid[4][4], int r, int c, int value);

static int	ft_height_at(int grid[4][4], int side, int item, int dist)
{
	if (side == 0)
		return (grid[dist][item]);
	if (side == 1)
		return (grid[3 - dist][item]);
	if (side == 2)
		return (grid[item][dist]);
	return (grid[item][3 - dist]);
}

static int	ft_countvisible(int grid[4][4], int side, int item)
{
	int	dist;
	int	value;
	int	tallest;
	int	visible;

	dist = 0;
	tallest = 0;
	visible = 0;
	while (dist < 4)
	{
		value = ft_height_at(grid, side, item, dist);
		if (value > tallest)
		{
			tallest = value;
			visible++;
		}
		dist++;
	}
	return (visible);
}

static int	ft_validgrid(int grid[4][4], int *num_input)
{
	int	side;
	int	item;

	side = 0;
	while (side < 4)
	{
		item = 0;
		while (item < 4)
		{
			if (ft_countvisible(grid, side, item)
				!= num_input[4 * side + item])
				return (0);
			item++;
		}
		side++;
	}
	return (1);
}

int	ft_solvegrid(int grid[4][4], int *num_input, int cell)
{
	int	r;
	int	c;
	int	value;

	if (cell == 16)
		return (ft_validgrid(grid, num_input));
	r = cell / 4;
	c = cell % 4;
	if (grid[r][c] != 0)
		return (ft_solvegrid(grid, num_input, cell + 1));
	value = 1;
	while (value <= 4)
	{
		if (ft_place(grid, r, c, value) == 1)
		{
			if (ft_solvegrid(grid, num_input, cell + 1) == 1)
				return (1);
			grid[r][c] = 0;
		}
		value++;
	}
	return (0);
}
