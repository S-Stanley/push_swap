/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 01:25:33 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/20 01:25:35 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	free_and_exit(char **matrice)
{
	free_that_matrice(matrice);
	print_text("Error\n");
	exit(0);
}

void	check_duplication(char **matrice)
{
	unsigned int	i;
	unsigned int	x;

	i = 0;
	while (matrice[i])
	{
		x = i + 1;
		while (matrice[x])
		{
			if (ft_atoi(matrice[x]) == ft_atoi(matrice[i]))
				free_and_exit(matrice);
			x++;
		}
		i++;
	}
}

void	verif_arg(char **matrice)
{
	unsigned int	i;
	unsigned int	x;

	i = 0;
	while (matrice[i])
	{
		x = 0;
		while (matrice[i][x])
		{
			if (matrice[i][x] > '9' || matrice[i][x] < '0')
				if (matrice[i][x] != '-')
					free_and_exit(matrice);
			if (ft_atoi(matrice[i]) < I_MIN || ft_atoi(matrice[i]) > I_MAX)
				free_and_exit(matrice);
			x++;
		}
		i++;
	}
	check_duplication(matrice);
	if (is_sorted(matrice))
		exit(0);
}
