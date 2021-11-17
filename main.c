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

t_pile	deal_with_three_arg(t_pile pile)
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

unsigned int	is_the_right_place_b(t_pile pile)
{
	if (min_arr(pile.matrice_b) > atoi(pile.matrice_a[0]))
	{
		if (min_arr(pile.matrice_b) == atoi(pile.matrice_b[0]))
			return (1);
	}
	else if (max_arr(pile.matrice_b) < atoi(pile.matrice_a[0]))
	{
		if (max_arr(pile.matrice_b) == atoi(pile.matrice_b[count_len_matrice(pile.matrice_b) - 1]))
			return (1);
	}
	else if (atoi(pile.matrice_a[0]) < atoi(pile.matrice_b[0]))
	{
		if (atoi(pile.matrice_a[0]) > atoi(pile.matrice_b[count_len_matrice(pile.matrice_b) - 1]))
			return (1);
	}
	return (0);
}

t_pile	deal_with_five_arg(t_pile pile)
{
	pile = push_b(pile.matrice_a, pile.matrice_b);
	pile = push_b(pile.matrice_a, pile.matrice_b);
	while (!is_sorted(pile.matrice_a))
		pile = deal_with_three_arg(pile);
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
	return (pile);
}

unsigned int	get_index(char **matrice, int value)
{
	unsigned int	i;

	i = 0;
	while (matrice[i])
	{
		if (atoi(matrice[i]) == value)
			return (i);
		i++;
	}
	return (i);
}

unsigned int	should_rotate(char **matrice, unsigned int index)
{
	unsigned int	size;

	size = count_len_matrice(matrice);

	if (index < (size / 2))
		return (1);
	return (0);
}

char	**deal_with_three_arg_reverse(char **matrice)
{
	while (!is_sorted(matrice))
	{
		if (atoi(matrice[0]) > atoi(matrice[1]))
			swap(matrice, "sa");
		else
			matrice = rotate_reverse(matrice, "rra");
	}
	return (matrice);
}

void	deal_with_hundreds(t_pile pile)
{
	while (count_len_matrice(pile.matrice_a) > 5)
	{
		while (min_arr(pile.matrice_a) != atoi(pile.matrice_a[0]))
		{
			if (should_rotate(pile.matrice_a, get_index(pile.matrice_a, min_arr(pile.matrice_a))) == 0)
				while (min_arr(pile.matrice_a) != atoi(pile.matrice_a[0]))
					rotate(pile.matrice_a, "ra");
			else
				while (min_arr(pile.matrice_a) != atoi(pile.matrice_a[0]))
					pile.matrice_a = rotate_reverse(pile.matrice_a, "rra");
		}
		pile = push_b(pile.matrice_a, pile.matrice_b);
	}
	pile = deal_with_five_arg(pile);
	while (count_len_matrice(pile.matrice_b) > 0)
		pile = push_a(pile.matrice_a, pile.matrice_b);
}

int	find_index_just_bigger(char **matrice, int nbr)
{
	unsigned int	i;
	int				to_return;

	i = 0;
	to_return = -1;
	while (matrice[i])
	{
		if (atoi(matrice[i]) > nbr)
		{
			if (to_return != -1)
			{
				if (atoi(matrice[i]) < atoi(matrice[to_return]))
					to_return = i;
			}
			else
				to_return = i;
		}
		i++;
	}
	return (to_return);
}

void	deal_with_five_hundred(t_pile pile, unsigned int size)
{
	pile = push_b(pile.matrice_a, pile.matrice_b);
	pile = push_b(pile.matrice_a, pile.matrice_b);
	if (atoi(pile.matrice_b[0]) > atoi(pile.matrice_b[1]))
		swap(pile.matrice_b, "rb");
	while (count_len_matrice(pile.matrice_a) > (size / 2))
	{
		if (should_rotate(pile.matrice_b, find_index_just_bigger(pile.matrice_b,atoi( pile.matrice_a[0]))))
			while (!is_the_right_place_b(pile))
				rotate(pile.matrice_b, "rb");
		else
			while (!is_the_right_place_b(pile))
				pile.matrice_b = rotate_reverse(pile.matrice_b, "rrb");
		pile = push_b(pile.matrice_a, pile.matrice_b);
	}
	if (should_rotate(pile.matrice_b, get_index(pile.matrice_b, min_arr(pile.matrice_b))))
		while (!is_sorted_reverse(pile.matrice_b))
			rotate(pile.matrice_b, "rb");
	else
		while (!is_sorted_reverse(pile.matrice_b))
			pile.matrice_b = rotate_reverse(pile.matrice_b, "rrb");
	// read_that_matrice(pile.matrice_a);
	// printf("************\n");
	// read_that_matrice(pile.matrice_b);
}

int main(int argc, char **argv)
{
	t_pile			pile;
	unsigned int	size;

	pile.matrice_a = NULL;
	pile.matrice_b = NULL;
	if (!argc || !argv)
		return (0);
	pile.matrice_a = parse_argv(argc, argv, pile.matrice_a);
	size = count_len_matrice(pile.matrice_a);
	if (argc <= 4)
		deal_with_three_arg(pile);
	else if (argc <= 6)
		deal_with_five_arg(pile);
	else if (argc <= 101)
		deal_with_five_hundred(pile, size);
		// deal_with_hundreds(pile);
	else
		deal_with_five_hundred(pile, size);
}