/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luborrer <luborrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 18:48:10 by luborrer          #+#    #+#             */
/*   Updated: 2026/09/19 21:33:49 by luborrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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

int	valid_pairs(int *pair)
{
	int	validpairs[5][2];

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
}
int	**ft_pairscheck(char *str)
{
	int	i;
	int	j;
	int	k;
	int	pos1;
	int	pos2;
	int	allpairs[16];



	// Step 1: fill array
	i = 0;// which row/column
	j = 0;// where in the row/column
	k = 0;// where in allpairs
	pos1 = i + j;
	pos2 = i + 4 + j;
	while (i < 4 && j < 4)
	{
		while (i < 2 && j < 4)	
		{
			allpairs[pos]str[pos1]
	}

	// How do I check the pairs?? 
}

int	main(int argc, char **argv[])
{
	int	*num_input;
	
	num_input = malloc(16 * sizeof(int));
	// count parameters
	if (argc != 2)
		return (1);

	// valid parameters
	if (ft_valid_input(argv[1], num_input) != 1)
		return (1);

	// from string to int array
	
	
	// valid pairsSo 
	
}