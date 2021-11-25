/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:50:48 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/20 13:52:23 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

char	**get_to_return(unsigned int size)
{
	char	**to_return;

	to_return = malloc(sizeof(char *) * size);
	if (!to_return)
	{
		print_text("Error while allocating pointer on get single arg");
		return (NULL);
	}
	return (to_return);
}

char	*check_error_single_arg(char **to_return, unsigned int x)
{
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
	return (to_return[x]);
}

t_loop	ft_loop(t_loop loop, char *str)
{
	if (str[loop.i] == ' ')
	{
		loop.to_return[++loop.x] = ft_substr(str, loop.last_index, loop.i);
		if (!loop.to_return[loop.x])
		{
			free_that_matrice(loop.to_return);
			loop.to_return = NULL;
			return (loop);
		}
		loop.last_index = loop.i + 1;
	}
	while (str[loop.i] == ' ')
		loop.i++;
	return (loop);
}

char	**get_single_arg(char *str)
{
	t_loop			loop;

	loop.i = -1;
	loop.x = -1;
	loop.last_index = 0;
	loop.to_return = get_to_return(count_occ(str, ' ') + 2);
	if (!loop.to_return)
		return (NULL);
	while (str[++loop.i] == 32)
		continue ;
	while (str[++loop.i])
	{
		loop = ft_loop(loop, str);
		if (!loop.to_return)
			return (NULL);
	}
	loop.to_return[++loop.x] = ft_substr(str, loop.last_index, loop.i);
	loop.to_return[loop.x] = check_error_single_arg(loop.to_return, loop.x);
	loop.to_return[++loop.x] = 0;
	return (loop.to_return);
}

char	**parse_argv(int argc, char **argv, char **nbr)
{
	unsigned int	i;
	char			**tmp;
	unsigned int	x;

	i = 1;
	while (i < (unsigned int)argc)
	{
		if (argv[i][0])
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
			free_that_matrice(tmp);
		}
		i++;
	}
	return (nbr);
}
