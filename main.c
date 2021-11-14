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

int	main(int argc, char **argv)
{
	char	**nbr;

	nbr = NULL;
	if (!argc || !argv)
		return (0);
	nbr = parse_argv(argc, argv, nbr);
	printf("%d\n", is_sorted(nbr));
	// read_that_matrice(nbr);
	free_that_matrice(nbr);
	return (0);
}
