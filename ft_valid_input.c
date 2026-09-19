/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luborrer <luborrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 18:48:16 by luborrer          #+#    #+#             */
/*   Updated: 2026/09/19 21:33:46 by luborrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strlen(char *str);

int	ft_valid_input(char *str, int *num_input)
{
    int i;
	int	len;

    i = 0;
	len = ft_strlen(str);
	// Check 1: length not 31 (16 digits + 15 spaces)
	if (len != 31)
		return(0); // define error output
    while (str[i] != '\0')
    {
        // Check 2: not digit or whitespace
		if (!((str[i] >= '1' && str[i] <= '4') || str[i] == 32))
        	return (0); 
		// Check 3: even slots not whitespace
		else if (i % 2 == 0 && str[i] != 32)
            return (0);
        // Check 4: odd slots NOT digit
		else if (i % 2 == 0 && !(str[i] >= '1' && str[i] <= '4'))
            return (0);
		else
			num_input[]
			i++;
    }
    return (1);
}
