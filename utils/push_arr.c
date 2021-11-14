/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 13:26:19 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/14 13:26:19 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

char	**push_arr(char **nbr, char *to_add)
{
	char			**to_return;
	unsigned int	i;

	to_return = malloc(sizeof(char *) * (count_len_matrice(nbr) + 2));
	if (!to_return)
	{
		printf("probleme allocation to_return in push_arr");
		free_that_matrice(nbr);
		return (NULL);
	}
	i = 0;
	if (nbr)
	{
		while (nbr[i])
		{		
			to_return[i] = nbr[i];
			i++;
		}
		free(nbr);
	}
	to_return[i] = to_add;
	to_return[++i] = 0;
	return (to_return);
}
