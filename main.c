/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 13:25:47 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/14 13:49:02 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_pile	sort_and_put(t_pile pile)
{
	while (!is_sorted(pile.matrice_a) || count_len_matrice(pile.matrice_b) > 0)
	{
		while (max_arr(pile.matrice_b) != atoi(pile.matrice_b[0]))
			pile.matrice_b = rotate(pile.matrice_b, "rb");
		pile = push_a(pile.matrice_a, pile.matrice_b);
	}
	return (pile);
}

int	main(int argc, char **argv)
{
	t_pile	pile;

	pile.matrice_a = NULL;
	pile.matrice_b = NULL;
	if (!argc || !argv)
		return (0);
	pile.matrice_a = parse_argv(argc, argv, pile.matrice_a);
	while (!is_sorted(pile.matrice_a))
		pile = ft_algo(pile);
	pile = sort_and_put(pile);
	printf("----\n");
	read_that_matrice(pile.matrice_a);
	free_that_matrice(pile.matrice_a);
	return (0);
}
