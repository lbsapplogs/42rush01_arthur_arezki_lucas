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
	
	
	// valid pairs
	
}