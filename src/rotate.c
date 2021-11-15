/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 01:56:01 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/15 01:56:02 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

char	**rotate(char **matrice, char *cmd)
{
	char			*tmp;
	unsigned int	i;

	tmp = matrice[0];
	i = 0;
	while (i + 1 < count_len_matrice(matrice))
	{
		matrice[i] = matrice[i + 1];
		i++;
	}
	matrice[i] = tmp;
	printf("%s\n", cmd);
	return (matrice);
}
