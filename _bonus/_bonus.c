/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _bonus.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:07:31 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/20 17:07:34 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"
#include "_bonus.h"

char	*get_commandes(unsigned int size)
{
	char			*buffer;
	unsigned int	readed;
	char			*new_buffer;

	buffer = NULL;
	new_buffer = NULL;
	while (1)
	{
		new_buffer = malloc(sizeof(char) * (size + 1));
		if (!new_buffer)
			return (0);
		readed = read(STDIN_FILENO, new_buffer, size);
		new_buffer[size] = 0;
		if (readed == 0)
		{
			free(new_buffer);
			break ;
		}
		buffer = ft_concat(buffer, new_buffer);
	}
	return (buffer);
}

unsigned int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

t_pile	launch_algo(t_pile pile, char **cmd)
{
	unsigned int	i;

	i = 0;
	while (cmd[i])
	{
		if (ft_strcmp(cmd[i], "sa") == 0)
			pile.matrice_a = swap(pile.matrice_a, "");
		if (ft_strcmp(cmd[i], "sb") == 0)
			pile.matrice_b = swap(pile.matrice_b, "");
		if (ft_strcmp(cmd[i], "ra") == 0)
			pile.matrice_a = rotate(pile.matrice_a, "");
		if (ft_strcmp(cmd[i], "rb") == 0)
			pile.matrice_b = rotate(pile.matrice_b, "");
		if (ft_strcmp(cmd[i], "rra") == 0)
			pile.matrice_a = rotate_reverse(pile.matrice_a, "");
		if (ft_strcmp(cmd[i], "rrb") == 0)
			pile.matrice_b = rotate_reverse(pile.matrice_b, "");
		i++;
	}
	return (pile);
}

t_pile	setup_pile(void)
{
	t_pile	pile;

	pile.matrice_a = NULL;
	pile.matrice_b = NULL;
	return (pile);
}

int	main(int argc, char **argv)
{
	unsigned int	size;
	char			**cmd;
	char			*buffer;
	t_pile			pile;

	pile = setup_pile();
	pile.matrice_a = parse_argv(argc, argv, pile.matrice_a);
	if (argc > 2)
		verif_arg(pile.matrice_a);
	buffer = get_commandes(1);
	if (buffer)
	{
		cmd = ft_split(buffer, '\n');
		free(buffer);
		pile = launch_algo(pile, cmd);
		free_that_matrice(cmd);
	}
	if (is_sorted(pile.matrice_a))
		print_text("OK\n");
	else
		print_text("KO\n");
	free_that_matrice(pile.matrice_a);
	if (pile.matrice_b)
		free(pile.matrice_b);
	return (0);
}
