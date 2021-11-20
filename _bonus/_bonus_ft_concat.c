/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _bonus_ft_concat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:14:59 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/20 17:15:00 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

char	*ft_concat(char *buffer, char *new_buffer)
{
	int				i;
	int				x;
	char			*to_return;
	int				size;

	size = ft_strlen(buffer) + ft_strlen(new_buffer) + 1;
	i = -1;
	to_return = malloc(sizeof(char) * size);
	if (!to_return)
	{
		free(buffer);
		free(new_buffer);
		exit(0);
	}
	if (buffer)
		while (buffer[++i])
			to_return[i] = buffer[i];
	x = -1;
	while (new_buffer[++x])
		to_return[++i] = new_buffer[x];
	to_return[++i] = 0;
	free(buffer);
	free(new_buffer);
	return (to_return);
}
