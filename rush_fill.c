/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_fill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luborrer <luborrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 19:30:50 by luborrer          #+#    #+#             */
/*   Updated: 2026/09/20 19:30:50 by luborrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_place(int grid[4][4], int r, int c, int value)
{
	int	i;

	if (grid[r][c] != 0 && grid[r][c] != value)
		return (0);
	i = 0;
	while (i < 4)
	{
		if (i != c && grid[r][i] == value)
			return (0);
		if (i != r && grid[i][c] == value)
			return (0);
		i++;
	}
	grid[r][c] = value;
	return (1);
}

static int	ft_fill_for1(int grid[4][4], int side, int item)
{
	int	r;
	int	c;

	r = 3 * (side == 1) + item * (side >= 2);
	c = item * (side < 2) + 3 * (side == 3);
	return (ft_place(grid, r, c, 4));
}

static int	ft_fill_for4(int grid[4][4], int side, int item)
{
	int	dist;
	int	placed;

	dist = 0;
	while (dist < 4)
	{
		if (side == 0)
			placed = ft_place(grid, dist, item, dist + 1);
		else if (side == 1)
			placed = ft_place(grid, 3 - dist, item, dist + 1);
		else if (side == 2)
			placed = ft_place(grid, item, dist, dist + 1);
		else
			placed = ft_place(grid, item, 3 - dist, dist + 1);
		if (placed != 1)
			return (0);
		dist++;
	}
	return (1);
}

int	ft_firsfill(int grid[4][4], int *num_input)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 4 * i;
			if (num_input[k + j] == 1
				&& ft_fill_for1(grid, i, j) != 1)
				return (0);
			if (num_input[k + j] == 4
				&& ft_fill_for4(grid, i, j) != 1)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
