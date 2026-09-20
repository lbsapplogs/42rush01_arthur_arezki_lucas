/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luborrer <luborrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 18:48:10 by luborrer          #+#    #+#             */
/*   Updated: 2026/09/20 15:14:09 by luborrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
	while (i <=5)
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
	int	j;
	int	valid_flag;

	i = 0;// which row/column
	j = i + 4;// where in the row/column
	valid_flag = 1;
	// Check column pairs
	while (i < 4 && valid_flag == 1)
	{
		valid_flag *= valid_pairs(num_input[i], num_input[j]);
		i++;	
	}
	// Check row pairs
	i += 4;
	while (i < 12 && valid_flag == 1)
	{
		valid_flag *= valid_pairs(num_input[i], num_input[j]);
		i++;	
	}
	return (valid_flag); 
}

int	ft_validcombinations(int *num_inputs)
{
	int	i;
	int	j;
	int	counter[5];
	
	j = 0 + i;
	while (j < 16)
	{
		i = 0;
		counter[1] = 0;
		counter[2] = 0;
		counter[3] = 0;
		counter[4] = 0;
		while (i < 4)
		{
			counter[num_inputs[j]] += 1;
			i++;
		}
		if (!(counter[1] > 1 || counter[2] > 3 || counter [3] > 2 || counter[4] > 1))
			return (0);
		j++;
	}
	return (1);
}

int	**ft_emptygrid(void) // Can I create a grid like this, will it be preserved in memory or do I need to malloc??
{
	int	grid[4][4];
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
	return (grid);
}

void	ft_fillrow(int *row);

void	ft_firstfill(int *num_inputs, int **grid)
{
	int	i;
	int	j;
	int	k;
	int	l;
	
	j = 0;
	while (j < 16)
	{
		i = 0;
		k = j + i;
		while (i < 4)
		{
			if (num_inputs[k] == 4)

				

			
			i++;
		}
		j++;
	}
}

int	main(int argc, char **argv[])
{
	int	num_input[16];
	int	**grid;
	
	grid = ft_emptygrid(); // **********do I need to malloc ???*************
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
	 
	// fill grid with known values


}