/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 01:56:06 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/15 01:56:07 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

char	**swap(char **matrice, char *cmd)
{
	char	*tmp;

	tmp = matrice[0];
	matrice[0] = matrice[1];
	matrice[1] = tmp;
	printf("%s\n", cmd);
	return (matrice);
}
