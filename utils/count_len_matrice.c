/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_len_matrice.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 13:25:56 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/14 13:25:57 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	count_len_matrice(char **matrice)
{
	unsigned int	i;

	i = 0;
	if (!matrice)
		return (0);
	while (matrice[i])
		i++;
	return (i);
}
