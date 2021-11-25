/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 13:25:47 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/21 17:21:16 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>

unsigned int	get_nb_rotation(unsigned int size)
{
	if (size == 100)
		return (20);
	if (size == 500)
		return (50);
	return (size / 5);
}

int	main(int argc, char **argv)
{
	t_pile			pile;
	unsigned int	size;

	pile.matrice_a = NULL;
	pile.matrice_b = NULL;
	if (!argc || !argv)
		return (0);
	pile.matrice_a = parse_argv(argc, argv, pile.matrice_a);
	if (!pile.matrice_a)
		return (0);
	if (argc > 1)
		verif_arg(pile.matrice_a);
	size = count_len_matrice(pile.matrice_a);
	if (size <= 3)
		pile = deal_with_three_arg(pile);
	else if (size <= 5)
		pile = deal_with_five_arg(pile);
	else
		pile = deal_with_a_lot(pile, get_nb_rotation(size));
	free_that_matrice(pile.matrice_a);
	if (pile.matrice_b)
		free_that_matrice(pile.matrice_b);
}
