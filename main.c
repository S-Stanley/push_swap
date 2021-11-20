/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 13:25:47 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/20 13:54:03 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
 	t_pile			pile;
 	unsigned int	size;

 	pile.matrice_a = NULL;
 	pile.matrice_b = NULL;
 	if (!argc || !argv)
 		return (0);
 	pile.matrice_a = parse_argv(argc, argv, pile.matrice_a);
 	if (argc > 2)
 		verif_arg(pile.matrice_a);
 	size = count_len_matrice(pile.matrice_a);
 	if (argc <= 4)
 		pile = deal_with_three_arg(pile);
 	else if (argc <= 6)
 		pile = deal_with_five_arg(pile);
 	else
 		pile = deal_with_five_hundred(pile, size);
 	free_that_matrice(pile.matrice_a);
 	if (pile.matrice_b)
		free_that_matrice(pile.matrice_b);
}
