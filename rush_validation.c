/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luborrer <luborrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 19:30:50 by luborrer          #+#    #+#             */
/*   Updated: 2026/09/20 19:30:50 by luborrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str);

int	ft_valid_input(char *str, int *num_input)
{
	int	i;
	int	j;

	if (ft_strlen(str) != 31)
		return (0);
	i = 0;
	j = 0;
	while (i < 31)
	{
		if (i % 2 == 0)
		{
			if (str[i] < '1' || str[i] > '4')
				return (0);
			num_input[j] = str[i] - '0';
			j++;
		}
		else if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

static int	ft_valid_pairs(int a, int b)
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
	while (i < 5)
	{
		if ((validpairs[i][0] == a && validpairs[i][1] == b)
			|| (validpairs[i][0] == b && validpairs[i][1] == a))
			valid_flag++;
		i++;
	}
	return (valid_flag);
}

int	ft_pairscheck(int *num_input)
{
	int	i;
	int	valid_flag;

	i = 0;
	valid_flag = 1;
	while (i < 4 && valid_flag == 1)
	{
		valid_flag *= ft_valid_pairs(num_input[i], num_input[i + 4]);
		i++;
	}
	i += 4;
	while (i < 12 && valid_flag == 1)
	{
		valid_flag *= ft_valid_pairs(num_input[i], num_input[i + 4]);
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
		if (counter[1] > 1 || counter[2] > 3
			|| counter[3] > 2 || counter[4] > 1)
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
