/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_that_matrice.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 13:26:23 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/14 13:26:23 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	read_that_matrice(char **matrice)
{
	unsigned int	i;

	i = 0;
	if (!matrice)
		return ;
	while (matrice[i])
	{
		print_text(matrice[i]);
		i++;
	}
}
