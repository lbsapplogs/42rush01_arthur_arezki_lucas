/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luborrer <luborrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 19:30:50 by luborrer          #+#    #+#             */
/*   Updated: 2026/09/20 19:30:50 by luborrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_error(void);
void	ft_emptygrid(int grid[4][4]);
int		ft_valid_input(char *str, int *num_input);
int		ft_pairscheck(int *num_input);
int		ft_validcombinations(int *num_inputs);
int		ft_validcorners(int *num_input);
int		ft_firsfill(int grid[4][4], int *num_input);
int		ft_solvegrid(int grid[4][4], int *num_input, int cell);
void	ft_printgrid(int grid[4][4]);

int	main(int argc, char **argv)
{
	int	num_input[16];
	int	grid[4][4];

	if (argc != 2)
		return (ft_error());
	ft_emptygrid(grid);
	if (ft_valid_input(argv[1], num_input) != 1)
		return (ft_error());
	if (ft_pairscheck(num_input) != 1)
		return (ft_error());
	if (ft_validcombinations(num_input) != 1)
		return (ft_error());
	if (ft_validcorners(num_input) != 1)
		return (ft_error());
	if (ft_firsfill(grid, num_input) != 1)
		return (ft_error());
	if (ft_solvegrid(grid, num_input, 0) != 1)
		return (ft_error());
	ft_printgrid(grid);
	return (0);
}
