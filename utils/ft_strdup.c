/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:19:57 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/20 15:19:58 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

char	*ft_strdup(char *str)
{
	unsigned int	i;
	char			*to_return;

	to_return = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!to_return)
		return (NULL);
	i = 0;
	while (str[i])
	{
		to_return[i] = str[i];
		i++;
	}
	to_return[i] = 0;
	return (to_return);
}
