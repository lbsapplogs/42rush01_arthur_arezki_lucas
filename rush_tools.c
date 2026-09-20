/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luborrer <luborrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 19:30:50 by luborrer          #+#    #+#             */
/*   Updated: 2026/09/20 19:30:50 by luborrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_emptygrid(int grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	ft_printgrid(int grid[4][4])
{
	int		r;
	int		c;
	char	num;

	r = 0;
	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			num = grid[r][c] + '0';
			write(1, &num, 1);
			if (c < 3)
				write(1, " ", 1);
			c++;
		}
		write(1, "\n", 1);
		r++;
	}
}

int	ft_error(void)
{
	write(1, "Error\n", 6);
	return (1);
}
