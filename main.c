/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 13:25:47 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/14 13:25:47 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	**get_single_arg(char *str)
{
	unsigned int	i;
	char			**to_return;
	unsigned int	x;
	unsigned int	last_index;

	i = 0;
	x = 0;
	last_index = 0;
	to_return = malloc(sizeof(char *) * (count_occ(str, ' ') + 2));
	if (!to_return)
	{
		printf("Error while allocating pointer on get single arg");
		exit(0);
	}
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		if (str[i] == ' ')
		{
			to_return[x] = ft_substr(str, last_index, i);
			x++;
			last_index = i + 1;
		}
		while (str[i] == ' ')
			i++;
		i++;
	}
	to_return[x] = ft_substr(str, last_index, i);
	to_return[++x] = 0;
	return (to_return);
}

char	**parse_argv(int argc, char **argv, char **nbr)
{
	unsigned int	i;
	char			**tmp;
	unsigned int	x;

	i = 1;
	while (i < argc)
	{
		tmp = get_single_arg(argv[i]);
		x = 0;
		while (tmp[x])
		{
			nbr = push_arr(nbr, tmp[x]);
			x++;
		}
		free(tmp);
		i++;
	}
	return (nbr);
}

int	main(int argc, char **argv)
{
	char	**nbr;

	nbr = NULL;
	if (!argc || !argv)
		return (0);
	nbr = parse_argv(argc, argv, nbr);
	read_that_matrice(nbr);
	free_that_matrice(nbr);
	return (0);
}
