/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 01:56:13 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/15 01:56:14 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	max_arr(char **matrice)
{
	unsigned int	i;
	int				max;

	i = 0;
	max = -1;
	while (matrice[i])
	{
		if (ft_atoi(matrice[i]) > max || max == -1)
			max = ft_atoi(matrice[i]);
		i++;
	}
	return (max);
}

int	min_arr(char **matrice)
{
	unsigned int	i;
	int				min;

	i = 0;
	min = -1;
	while (matrice[i])
	{
		if (ft_atoi(matrice[i]) < min || min == -1)
			min = ft_atoi(matrice[i]);
		i++;
	}
	return (min);
}

unsigned int	find_in_arr(char **matrice, int to_find)
{
	unsigned int	i;

	i = 0;
	if (!matrice)
		return (0);
	while (matrice[i])
	{
		if (ft_atoi(matrice[i]) == to_find)
			return (1);
		i++;
	}
	return (0);
}

unsigned int	is_sorted_globally(char **matrice)
{
	int				min;
	unsigned int	i;
	unsigned int	max_index;

	min = min_arr(matrice);
	i = 1;
	while (matrice[i] && ft_atoi(matrice[i]) != min)
	{
		if (ft_atoi(matrice[i]) < ft_atoi(matrice[i - 1]))
			return (0);
		i++;
	}
	max_index = i - 1;
	while (matrice[i] && i != max_index && i + 1 <= count_len_matrice(matrice) - 1)
	{
		if (ft_atoi(matrice[i]) > ft_atoi(matrice[i + 1]))
			return (0);
		i++;
	}
	return (1);
}
