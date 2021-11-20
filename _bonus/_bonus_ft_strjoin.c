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

void	ft_concat(const char *s1, const char *s2, char *res)
{
	int		i;
	int		n;

	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	n = i;
	i = 0;
	while (s2[i])
	{
		res[n] = s2[i];
		n++;
		i++;
	}
	res[n] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		len_s1;
	int		len_s2;

	if (s1 == NULL)
		s1 = ft_strdup("");
	if (s2 == NULL)
		s2 = ft_strdup("");
	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	res = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!res)
		return (NULL);
	ft_concat(s1, s2, res);
	return (res);
}
