/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 01:56:01 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/20 13:06:27 by sserbin          ###   ########.fr       */
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
	print_text(cmd);
	return (matrice);
}

char	**rotate_reverse(char **matrice, char *cmd)
{
	char			**to_return;
	unsigned int	i;

	to_return = malloc(sizeof(char *) * (count_len_matrice(matrice) + 1));
	if (!to_return)
	{
		free_that_matrice(matrice);
		exit(0);
	}
	i = 0;
	to_return[i] = matrice[count_len_matrice(matrice) - 1];
	while (matrice[++i])
		to_return[i] = matrice[i - 1];
	to_return[i] = 0;
	free(matrice);
	print_text(cmd);
	return (to_return);
}
