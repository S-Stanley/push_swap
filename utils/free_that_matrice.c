/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_that_matrice.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 13:26:07 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/14 13:26:08 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	free_that_matrice(char **matrice)
{
	unsigned int	i;

	i = 0;
	while (matrice[i])
	{
		free(matrice[i]);
		i++;
	}
	free(matrice);
}
