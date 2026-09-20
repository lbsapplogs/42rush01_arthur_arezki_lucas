/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luborrer <luborrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 18:48:10 by luborrer          #+#    #+#             */
/*   Updated: 2026/09/20 15:14:11 by luborrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
}

int	ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
		i++;
	return(i);
}

int	ft_valid_input(char *str, int *num_input)
{
    int i;
	int	j;
	int	len;

    i = 0;
	j = 0;
	len = ft_strlen(str);
	// Check 1: length not 31 (16 digits + 15 spaces)
	if (len != 31)
		return(0); // define error output
    while (str[i] != '\0')
    {
        // Check 2: not digit or whitespace
		if (!((str[i] >= '1' && str[i] <= '4') || str[i] == 32))
        	return (0); 
		// Check 3: odd slots not whitespace
		else if (i % 2 != 0 && str[i] != 32)
            return (0);
        // Check 4: even slots NOT digit
		else if (i % 2 == 0 && !(str[i] >= '1' && str[i] <= '4'))
			return (0);
		else if (i % 2 == 0 && (str[i] >= '1' && str[i] <= '4'))
		{
			num_input[j] = str[i] - '0';
			j++;
		}
		i++;
    }
    return (1);
}

int	valid_pairs(int a, int b)
{
	int	i;
	int	validpairs[5][2];
	int	valid_flag;

	i = 0;
	valid_flag = 0;
	validpairs[0][0] = 4;
	validpairs[0][1] = 1;
	validpairs[1][0] = 3;
	validpairs[1][1] = 2;
	validpairs[2][0] = 3;
	validpairs[2][1] = 1;
	validpairs[3][0] = 2;
	validpairs[3][1] = 2;
	validpairs[4][0] = 2;
	validpairs[4][1] = 1;
	while (i <5)
	{
		if ((validpairs[i][0] == a && validpairs[i][1] == b) || (validpairs[i][0] == b && validpairs[i][1] == a))
			valid_flag++;
		i++;
	}
	return (valid_flag);
}

int	ft_pairscheck(int *num_input)
{
	int	i;
	int	valid_flag;

	i = 0;// which row/column
	valid_flag = 1;
	// Check column pairs
	while (i < 4 && valid_flag == 1)
	{
		valid_flag *= valid_pairs(num_input[i], num_input[i + 4]);
		i++;	
	}
	// Check row pairs
	i += 4;
	while (i < 12 && valid_flag == 1)
	{
		valid_flag *= valid_pairs(num_input[i], num_input[i + 4]);
		i++;	
	}
	return (valid_flag); 
}

int	ft_validcombinations(int *num_inputs)
{
	int	i;
	int	j;
	int	counter[5];
	
	j = 0;
	while (j < 16)
	{
		i = 0;
		counter[1] = 0;
		counter[2] = 0;
		counter[3] = 0;
		counter[4] = 0;
		while (i < 4)
		{
			counter[num_inputs[j + i]] += 1;
			i++;
		}
		if ((counter[1] > 1 || counter[2] > 3 || counter [3] > 2 || counter[4] > 1))
			return (0);
		j += 4;
	}
	return (1);
}

int	ft_validcorners(int *num_input)
{
	if ((num_input[0] == 1) != (num_input[8] == 1))
		return (0);
	if ((num_input[3] == 1) != (num_input[12] == 1))
		return (0);
	if ((num_input[4] == 1) != (num_input[11] == 1))
		return (0);
	if ((num_input[7] == 1) != (num_input[15] == 1))
		return (0);
	return (1);
}

void	ft_emptygrid(int grid[4][4]) // Can I create a grid like this, will it be preserved in memory or do I need to malloc??
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

void	ft_fill_for1(int grid[4][4], int side, int item)
{
	int	r;
	int	c;

	r = 3 * (side == 1) + item * (side >= 2);
	c = item * (side < 2) + 3 * (side == 3);
	grid[r][c] = 4;
}

void	ft_fill_for4(int grid[4][4], int side, int item)
{
	int	dist;

	dist = 0;
	while (dist < 4)
	{
		if (side == 0)
			grid[dist][item] = dist + 1;
		else if (side == 1)
			grid[3 - dist][item] = dist + 1;
		else if (side == 2)
			grid[item][dist] = dist + 1;
		else
			grid[item][3 - dist] = dist + 1;
		dist++;
	}
}

void	ft_firsfill(int grid[4][4], int *num_input)
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
			if (num_input[k + j] == 1)
				ft_fill_for1(grid, i, j);
			else if (num_input[k + j] == 4)
				ft_fill_for4(grid, i, j);
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

int	main(int argc, char **argv)
{
	int	num_input[16];
	int	grid[4][4];
	
	
	ft_emptygrid(grid); // **********do I need to malloc ???*************
	// count parameters
	if (argc != 2)
		return (1);

	// valid parameters
	if (ft_valid_input(argv[1], num_input) != 1)
		return (1);

	// valid pairs
	if (ft_pairscheck(num_input) != 1)
		return (1);
	
	// valid combinations 
	if (ft_validcombinations(num_input) != 1)
		return (1);
	
	// valid start end (if 1 or 4)
	if (ft_validcorners(num_input) != 1)
		return (1);

	// fill grid with known values
	ft_firsfill(grid, num_input);

	ft_printgrid(grid);
	return (0);


}
