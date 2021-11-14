/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_occurence.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 13:26:03 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/14 13:26:04 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	count_occ(char *str, char occ)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i] == occ)
		i++;
	while (str[i])
	{
		if (str[i] == occ)
			count++;
		while (str[i] == occ)
			i++;
		i++;
	}
	return (count);
}
