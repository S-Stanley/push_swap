/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 13:25:47 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/14 13:49:02 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	**get_to_return(unsigned int size)
{
	char	**to_return;

	to_return = malloc(sizeof(char *) * size);
	if (!to_return)
	{
		printf("Error while allocating pointer on get single arg");
		return (NULL);
	}
	return (to_return);
}

char	**get_single_arg(char *str)
{
	int				i;
	char			**to_return;
	int				x;
	unsigned int	last_index;

	i = -1;
	x = -1;
	last_index = 0;
	to_return = get_to_return(count_occ(str, ' ') + 2);
	if (!to_return)
		return (NULL);
	while (str[++i])
	{
		if (str[i] == ' ')
		{
			to_return[++x] = ft_substr(str, last_index, i);
			if (!to_return[x])
			{
				free_that_matrice(to_return);
				return (NULL);
			}
			last_index = i + 1;
		}
		while (str[i] == ' ')
			i++;
	}
	to_return[++x] = ft_substr(str, last_index, i);
	if (!to_return[x])
	{
		free_that_matrice(to_return);
		return (NULL);
	}
	if (!to_return[x][0])
	{
		free(to_return[x]);
		to_return[x] = 0;
	}
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
		if (!tmp)
		{
			free_that_matrice(nbr);
			exit(0);
		}
		x = 0;
		while (tmp[x])
		{
			nbr = push_arr(nbr, tmp[x]);
			if (!nbr)
				exit(0);
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
