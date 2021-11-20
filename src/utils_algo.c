/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 01:38:50 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/20 01:38:51 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

unsigned int	is_the_right_place(t_pile pile)
{
	int	size;

	size = count_len_matrice(pile.matrice_a);
	if (min_arr(pile.matrice_a) > ft_atoi(pile.matrice_b[0]))
	{
		if (min_arr(pile.matrice_a) == ft_atoi(pile.matrice_a[0]))
			return (1);
	}
	else if (max_arr(pile.matrice_a) < ft_atoi(pile.matrice_b[0]))
	{
		if (max_arr(pile.matrice_a) == ft_atoi(pile.matrice_a[size -1]))
			return (1);
	}
	else if (ft_atoi(pile.matrice_b[0]) < ft_atoi(pile.matrice_a[0]))
	{
		if (ft_atoi(pile.matrice_b[0]) > ft_atoi(pile.matrice_a[size -1]))
			return (1);
	}
	return (0);
}

unsigned int	should_start_with_rotate(char **matrice, char **grp)
{
	unsigned int	i;
	unsigned int	index;
	unsigned int	count;

	i = 0;
	index = -1;
	while (matrice[i])
	{
		if (find_in_arr(grp, ft_atoi(matrice[i])))
			index = i;
		i++;
	}
	i = count_len_matrice(matrice) -1;
	count = 0;
	while (i > 0)
	{
		if (find_in_arr(grp, ft_atoi(matrice[i])))
		{
			if (count < index)
				return (0);
		}
		count++;
		i--;
	}
	return (1);
}

unsigned int	get_index(char **matrice, int value)
{
	unsigned int	i;

	i = 0;
	while (matrice[i])
	{
		if (ft_atoi(matrice[i]) == value)
			return (i);
		i++;
	}
	return (i);
}

unsigned int	should_rotate(char **matrice, unsigned int index)
{
	unsigned int	size;

	size = count_len_matrice(matrice);
	if (index < (size / 2))
		return (1);
	return (0);
}

char	**find_the_lowers(char **matrice, int nb_rotation)
{
	char			**buffer;
	unsigned int	i;
	char			*min;
	unsigned int	x;

	buffer = NULL;
	buffer = push_arr(buffer, ft_itoa(min_arr(matrice)));
	x = 0;
	while (x < (unsigned int)nb_rotation - 1)
	{
		i = 0;
		min = NULL;
		while (matrice[i])
		{
			if ((!min || ft_atoi(matrice[i]) < ft_atoi(min)))
			{
				if (!find_in_arr(buffer, ft_atoi(matrice[i])))
					min = matrice[i];
			}
			i++;
		}
		buffer = push_arr(buffer, min);
		x++;
	}
	return (buffer);
}
