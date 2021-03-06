/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 01:27:50 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/20 01:27:51 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	ft_iswhitespace(char c)
{
	if (c >= 9 && c <= 13)
	{
		return (1);
	}
	else if (c == 32)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

long long	ft_atoi(char *str)
{
	int			i;
	long long	res;
	long long	pos;

	i = 0;
	pos = 1;
	res = 0;
	while (str[i] && ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			pos = pos * -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
		if (res > 2147483647 && pos == 1)
			return (2147483648);
		if (res > 2147483648 && pos == -1)
			return (-2147483649);
	}
	return (res * pos);
}
