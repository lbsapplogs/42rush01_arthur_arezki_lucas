/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luborrer <luborrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 18:48:10 by luborrer          #+#    #+#             */
/*   Updated: 2026/09/19 19:40:33 by luborrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



int	main(int argc, char **argv[])
{
	// count parameters
	if (argc != 2)
		return (1);

	// valid parameters
	if (ft_valid_input(argv[1]) != 0)
		return (1);

	// valid pairs
	
}