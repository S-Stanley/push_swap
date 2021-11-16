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

t_pile	sort_and_put(t_pile pile)
{
	while (!is_sorted(pile.matrice_a) || count_len_matrice(pile.matrice_b) > 0)
	{
		// read_that_matrice(pile.matrice_a);
		// printf("**\n");
		// printf("->%d\n", count_len_matrice(pile.matrice_b));
		// printf("---------\n");
		while (max_arr(pile.matrice_b) != atoi(pile.matrice_b[0]))
			pile.matrice_b = rotate(pile.matrice_b, "rb");
		pile = push_a(pile.matrice_a, pile.matrice_b);
	}
	return (pile);
}

char	*malloc_and_give(const char *str)
{
	char	*to_return;

	to_return = malloc(sizeof(char) * 2);
	to_return = strdup(str);
	return (to_return);
}

t_pile	get_back_b_to_a(t_pile pile)
{
	while (count_len_matrice(pile.matrice_b) > 0)
	{
		while (min_arr(pile.matrice_a) != atoi(pile.matrice_a[0]))
			pile.matrice_a = rotate(pile.matrice_a, "ra");
		while (min_arr(pile.matrice_b) != atoi(pile.matrice_b[0]))
			pile.matrice_b = rotate(pile.matrice_b, "ra");
		pile = push_a(pile.matrice_a, pile.matrice_b);
	}
	return (pile);
}

unsigned int	is_sorted_globally(char **matrice)
{
	int				min;
	unsigned int	i;
	unsigned int	max_index;

	min = min_arr(matrice);
	i = 1;
	while (matrice[i] && atoi(matrice[i]) != min)
	{
		if (atoi(matrice[i]) < atoi(matrice[i - 1]))
			return (0);
		i++;
	}
	max_index = i - 1;
	while (matrice[i] && i != max_index && i + 1 <= count_len_matrice(matrice) - 1)
	{
		if (atoi(matrice[i]) > atoi(matrice[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

t_pile	mex(t_pile pile)
{
	while (!is_sorted(pile.matrice_a))
	{
		while (max_arr(pile.matrice_a) != atoi(pile.matrice_a[0]))
			pile.matrice_a = rotate(pile.matrice_a, "ra");
		pile = push_b(pile.matrice_a, pile.matrice_b);
		if (is_sorted_globally(pile.matrice_a))
		{
			pile = get_back_b_to_a(pile);
			break;
		}
	}
	while (!is_sorted(pile.matrice_a))
		pile.matrice_a = rotate(pile.matrice_a, "ra");
	return (pile);
}

t_pile	deal_with_3_arg(t_pile pile)
{
	while (!is_sorted(pile.matrice_a))
	{
		if (atoi(pile.matrice_a[0]) > atoi(pile.matrice_a[1]))
			swap(pile.matrice_a, "sa");
		else
			pile.matrice_a = rotate_reverse(pile.matrice_a, "rra");
	}
	return (pile);
}

unsigned int	is_the_right_place(t_pile pile)
{
	if (min_arr(pile.matrice_a) > atoi(pile.matrice_b[0]))
	{
		if (min_arr(pile.matrice_a) == atoi(pile.matrice_a[0]))
			return (1);
	}
	else if (max_arr(pile.matrice_a) < atoi(pile.matrice_b[0]))
	{
		if (max_arr(pile.matrice_a) == atoi(pile.matrice_a[count_len_matrice(pile.matrice_a) - 1]))
			return (1);
	}
	else if (atoi(pile.matrice_b[0]) < atoi(pile.matrice_a[0]))
	{
		if (atoi(pile.matrice_b[0]) > atoi(pile.matrice_a[count_len_matrice(pile.matrice_a) - 1]))
			return (1);
	}
	return (0);
}

void	deal_with_5_arg(t_pile pile)
{
	pile = push_b(pile.matrice_a, pile.matrice_b);
	pile = push_b(pile.matrice_a, pile.matrice_b);
	while (!is_sorted(pile.matrice_a))
		pile = deal_with_3_arg(pile);
	if (atoi(pile.matrice_b[0]) < atoi(pile.matrice_b[1]))
		swap(pile.matrice_b, "sb");
	while (!is_the_right_place(pile))
		pile.matrice_a = rotate(pile.matrice_a, "ra");
	pile = push_a(pile.matrice_a, pile.matrice_b);
	while (!is_the_right_place(pile))
		pile.matrice_a = rotate(pile.matrice_a, "ra");
	pile = push_a(pile.matrice_a, pile.matrice_b);
	while (!is_sorted(pile.matrice_a))
		pile.matrice_a = rotate_reverse(pile.matrice_a, "rra");
}

int main(int argc, char **argv)
{
	t_pile	pile;

	pile.matrice_a = NULL;
	pile.matrice_b = NULL;
	if (!argc || !argv)
		return (0);
	pile.matrice_a = parse_argv(argc, argv, pile.matrice_a);
	if (argc <= 4)
		deal_with_3_arg(pile);
	else if (argc <= 6)
		deal_with_5_arg(pile);
	else if (argc <= 101)
		return (0);
	else
		return(0);
}