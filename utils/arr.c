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
		if (atoi(matrice[i]) > max || max == -1)
			max = atoi(matrice[i]);
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
		if (atoi(matrice[i]) < min || min == -1)
			min = atoi(matrice[i]);
		i++;
	}
	return (min);
}
