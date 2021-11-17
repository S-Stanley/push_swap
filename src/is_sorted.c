/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 01:55:46 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/15 01:55:46 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

unsigned int	is_sorted(char	**stack)
{
	unsigned int	i;

	if (count_len_matrice(stack) <= 1)
		return (1);
	i = 1;
	while (stack[i])
	{
		if (atoi(stack[i]) < atoi(stack[i - 1]))
			return (0);
		i++;
	}
	return (1);
}

unsigned int	is_sorted_reverse(char **stack)
{
	unsigned int	i;

	if (count_len_matrice(stack) <= 1)
		return (1);
	i = count_len_matrice(stack);
	while (--i > 0)
	{
		if (atoi(stack[i]) < atoi(stack[i - 1]))
			return (0);
	}
	return (1);
}
