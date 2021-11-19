/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 01:55:41 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/15 01:55:42 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_pile	ft_algo(t_pile pile)
{
	if (max_arr(pile.matrice_a) == ft_atoi(pile.matrice_a[0]))
		pile.matrice_a = rotate(pile.matrice_a, "ra");
	else
		pile = push_b(pile.matrice_a, pile.matrice_b);
	return (pile);
}
