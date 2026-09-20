/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyscraper.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luborrer <luborrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 18:20:00 by luborrer          #+#    #+#             */
/*   Updated: 2026/09/20 18:25:00 by luborrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SKYSCRAPER_H
# define SKYSCRAPER_H

# include <unistd.h>

/*
** --- Fonctions de Parsing et Utilitaires ---
*/
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_valid_input(char *str, int *num_input);
int		valid_pairs(int a, int b);
int		ft_pairscheck(int *num_input);
int		ft_validcombinations(int *num_inputs);

int		solve_skyscraper(int grid[4][4], int *num_input, int r, int c);
void	print_grid(int grid[4][4]);

#endif

