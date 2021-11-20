/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 01:55:41 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/20 13:15:50 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_pile	deal_with_five_arg(t_pile pile)
{
	pile = push_b(pile.matrice_a, pile.matrice_b);
	pile = push_b(pile.matrice_a, pile.matrice_b);
	while (!is_sorted(pile.matrice_a))
		pile = deal_with_three_arg(pile);
	if (ft_atoi(pile.matrice_b[0]) < ft_atoi(pile.matrice_b[1]))
		swap(pile.matrice_b, "sb\n");
	while (!is_the_right_place(pile))
		pile.matrice_a = rotate(pile.matrice_a, "ra\n");
	pile = push_a(pile.matrice_a, pile.matrice_b);
	while (!is_the_right_place(pile))
		pile.matrice_a = rotate(pile.matrice_a, "ra\n");
	pile = push_a(pile.matrice_a, pile.matrice_b);
	while (!is_sorted(pile.matrice_a))
		pile.matrice_a = rotate_reverse(pile.matrice_a, "rra\n");
	return (pile);
}

t_pile	deal_with_five_hundred(t_pile pile, unsigned int size)
{
	char			**grp;
	unsigned int	to_start;
	unsigned int	rotations;
	unsigned int	x;

	rotations = size / 5;
	x = 0;
	while (count_len_matrice(pile.matrice_a) > 2)
	{
		grp = find_the_lowers(pile.matrice_a, rotations);
		to_start = should_start_with_rotate(pile.matrice_a, grp);
		x = 0;
		while (x < rotations)
		{
			while (!find_in_arr(grp, ft_atoi(pile.matrice_a[0])))
			{
				if (to_start)
					rotate(pile.matrice_a, "ra\n");
				else
					pile.matrice_a = rotate_reverse(pile.matrice_a, "rra\n");
			}
			pile = push_b(pile.matrice_a, pile.matrice_b);
			x++;
		}
		free_that_matrice(grp);
	}
	while (count_len_matrice(pile.matrice_b) > 0)
	{
		if (should_rotate(pile.matrice_b, get_index(pile.matrice_b, max_arr(pile.matrice_b))))
			while (ft_atoi(pile.matrice_b[0]) != max_arr(pile.matrice_b))
				rotate(pile.matrice_b, "rb\n");
		else
			while (ft_atoi(pile.matrice_b[0]) != max_arr(pile.matrice_b))
				pile.matrice_b = rotate_reverse(pile.matrice_b, "rrb\n");
		pile = push_a(pile.matrice_a, pile.matrice_b);
	}
	return (pile);
}

t_pile	deal_with_three_arg(t_pile pile)
{
	while (!is_sorted(pile.matrice_a))
	{
		if (ft_atoi(pile.matrice_a[0]) > ft_atoi(pile.matrice_a[1]))
			swap(pile.matrice_a, "sa\n");
		else
			pile.matrice_a = rotate_reverse(pile.matrice_a, "rra\n");
	}
	return (pile);
}
