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
		while (max_arr(pile.matrice_b) != ft_atoi(pile.matrice_b[0]))
			pile.matrice_b = rotate(pile.matrice_b, "rb\n");
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
		while (min_arr(pile.matrice_a) != ft_atoi(pile.matrice_a[0]))
			pile.matrice_a = rotate(pile.matrice_a, "ra");
		while (min_arr(pile.matrice_b) != ft_atoi(pile.matrice_b[0]))
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
	while (matrice[i] && ft_atoi(matrice[i]) != min)
	{
		if (ft_atoi(matrice[i]) < ft_atoi(matrice[i - 1]))
			return (0);
		i++;
	}
	max_index = i - 1;
	while (matrice[i] && i != max_index && i + 1 <= count_len_matrice(matrice) - 1)
	{
		if (ft_atoi(matrice[i]) > ft_atoi(matrice[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

t_pile	mex(t_pile pile)
{
	while (!is_sorted(pile.matrice_a))
	{
		while (max_arr(pile.matrice_a) != ft_atoi(pile.matrice_a[0]))
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
		if (ft_atoi(pile.matrice_a[0]) > ft_atoi(pile.matrice_a[1]))
			swap(pile.matrice_a, "sa");
		else
			pile.matrice_a = rotate_reverse(pile.matrice_a, "rra\n");
	}
	return (pile);
}

unsigned int	is_the_right_place(t_pile pile)
{
	if (min_arr(pile.matrice_a) > ft_atoi(pile.matrice_b[0]))
	{
		if (min_arr(pile.matrice_a) == ft_atoi(pile.matrice_a[0]))
			return (1);
	}
	else if (max_arr(pile.matrice_a) < ft_atoi(pile.matrice_b[0]))
	{
		if (max_arr(pile.matrice_a) == ft_atoi(pile.matrice_a[count_len_matrice(pile.matrice_a) - 1]))
			return (1);
	}
	else if (ft_atoi(pile.matrice_b[0]) < ft_atoi(pile.matrice_a[0]))
	{
		if (ft_atoi(pile.matrice_b[0]) > ft_atoi(pile.matrice_a[count_len_matrice(pile.matrice_a) - 1]))
			return (1);
	}
	return (0);
}

unsigned int	is_the_right_place_b(t_pile pile)
{
	if (min_arr(pile.matrice_b) > ft_atoi(pile.matrice_a[0]))
	{
		if (min_arr(pile.matrice_b) == ft_atoi(pile.matrice_b[0]))
			return (1);
	}
	else if (max_arr(pile.matrice_b) < ft_atoi(pile.matrice_a[0]))
	{
		if (max_arr(pile.matrice_b) == ft_atoi(pile.matrice_b[count_len_matrice(pile.matrice_b) - 1]))
			return (1);
	}
	else if (ft_atoi(pile.matrice_a[0]) < ft_atoi(pile.matrice_b[0]))
	{
		if (ft_atoi(pile.matrice_a[0]) > ft_atoi(pile.matrice_b[count_len_matrice(pile.matrice_b) - 1]))
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
	if (ft_atoi(pile.matrice_b[0]) < ft_atoi(pile.matrice_b[1]))
		swap(pile.matrice_b, "sb");
	while (!is_the_right_place(pile))
		pile.matrice_a = rotate(pile.matrice_a, "ra");
	pile = push_a(pile.matrice_a, pile.matrice_b);
	while (!is_the_right_place(pile))
		pile.matrice_a = rotate(pile.matrice_a, "ra");
	pile = push_a(pile.matrice_a, pile.matrice_b);
	while (!is_sorted(pile.matrice_a))
		pile.matrice_a = rotate_reverse(pile.matrice_a, "rra\n");
	return (pile);
}

unsigned int	get_index(char **matrice, int value)
{
	unsigned int	i;

	i = 0;
	while (matrice[i])
	{
		if (ft_atoi(matrice[i]) == value)
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
		if (ft_atoi(matrice[0]) > ft_atoi(matrice[1]))
			swap(matrice, "sa");
		else
			matrice = rotate_reverse(matrice, "rra\n");
	}
	return (matrice);
}

void	deal_with_hundreds(t_pile pile)
{
	while (count_len_matrice(pile.matrice_a) > 5)
	{
		while (min_arr(pile.matrice_a) != ft_atoi(pile.matrice_a[0]))
		{
			if (should_rotate(pile.matrice_a, get_index(pile.matrice_a, min_arr(pile.matrice_a))) == 0)
				while (min_arr(pile.matrice_a) != ft_atoi(pile.matrice_a[0]))
					rotate(pile.matrice_a, "ra");
			else
				while (min_arr(pile.matrice_a) != ft_atoi(pile.matrice_a[0]))
					pile.matrice_a = rotate_reverse(pile.matrice_a, "rra\n");
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
		if (ft_atoi(matrice[i]) > nbr)
		{
			if (to_return != -1)
			{
				if (ft_atoi(matrice[i]) < ft_atoi(matrice[to_return]))
					to_return = i;
			}
			else
				to_return = i;
		}
		i++;
	}
	return (to_return);
}

unsigned int	get_chunk(char **matrice, unsigned int max_to_search)
{
	int				i;
	int				min;
	unsigned int	index;
	unsigned int	count;

	i = -1;
	min = max_arr(matrice) + 1;
	while (matrice[++i] && i < (int)max_to_search)
	{
		if (ft_atoi(matrice[i]) < min)
		{
			min = ft_atoi(matrice[i]);
			index = i;
		}
	}
	count = 0;
	i = count_len_matrice(matrice) + 1;
	while (matrice[--i] && count < max_to_search)
	{
		if (ft_atoi(matrice[i]) < min)
		{
			min = ft_atoi(matrice[i]);
			index = i;
		}
	}
	return (index);
}

unsigned int	find_in_arr(char **matrice, int	to_find)
{
	unsigned int	i;

	i = 0;
	if (!matrice)
		return (0);
	while (matrice[i])
	{
		if (ft_atoi(matrice[i]) == to_find)
			return (1);
		i++;
	}
	return (0);
}

char	**find_the_lowers(char **matrice, int nb_rotation)
{
	char			**buffer;
	unsigned int	i;
	char			*min;
	unsigned int	x;

	buffer = NULL;
	buffer = push_arr(buffer, ft_itoa(min_arr(matrice)));
	x = 0;
	while (x < (unsigned int)nb_rotation - 1)
	{
		i = 0;
		min = NULL;
		while (matrice[i])
		{
			if ((!min || ft_atoi(matrice[i]) < ft_atoi(min)) && !find_in_arr(buffer, ft_atoi(matrice[i])))
				min = matrice[i];
			i++;
		}
		buffer = push_arr(buffer, min);
		x++;
	}
	return (buffer);
}

unsigned int	should_start_with_rotate(char **matrice, char **grp)
{
	unsigned int	i;
	unsigned int	index;
	unsigned int	count;

	i = 0;
	index = -1;
	while (matrice[i])
	{
		if (find_in_arr(grp, ft_atoi(matrice[i])))
			index = i;
		i++;
	}
	i = count_len_matrice(matrice) -1;
	count = 0;
	while (i > 0)
	{
		if (find_in_arr(grp, ft_atoi(matrice[i])))
		{
			if (count < index)
				return (0);
		}
		count++;
		i--;
	}
	return (1);
}

void	deal_with_five_hundred(t_pile pile, unsigned int size)
{
	char			**grp;
	unsigned int	to_start;
	unsigned int	rotations;
	unsigned int	x;

	rotations = size / 5;
	x = 0;
	while (count_len_matrice(pile.matrice_a) > 2)
	{
		grp = find_the_lowers(pile.matrice_a, rotations);
		to_start = should_start_with_rotate(pile.matrice_a, grp);
		x = 0;
		while (x < rotations)
		{
			while (!find_in_arr(grp, ft_atoi(pile.matrice_a[0])))
			{
				if (to_start)
					rotate(pile.matrice_a, "ra\n");
				else
					pile.matrice_a = rotate_reverse(pile.matrice_a, "rra\n");
			}
			pile = push_b(pile.matrice_a, pile.matrice_b);
			x++;
		}
	}
	while (count_len_matrice(pile.matrice_b) > 0)
	{
		if (should_rotate(pile.matrice_b, get_index(pile.matrice_b, max_arr(pile.matrice_b))))
			while (ft_atoi(pile.matrice_b[0]) != max_arr(pile.matrice_b))
				rotate(pile.matrice_b, "rb\n");
		else
			while (ft_atoi(pile.matrice_b[0]) != max_arr(pile.matrice_b))
				pile.matrice_b = rotate_reverse(pile.matrice_b, "rrb\n");
		pile = push_a(pile.matrice_a, pile.matrice_b);
	}
}

void	print_text(char *str)
{
	write(1, str, ft_strlen(str));
}

void	free_and_exit(char **matrice)
{
	free_that_matrice(matrice);
	print_text("Error\n");
	exit(0);
}

void	check_duplication(char **matrice)
{
	unsigned int	i;
	unsigned int	x;

	i = 0;
	while (matrice[i])
	{
		x = i + 1;
		while (matrice[x])
		{
			if (atoi(matrice[x]) == atoi(matrice[i]))
				free_and_exit(matrice);
			x++;
		}
		i++;
	}
}

#include "stdio.h"

void	verif_arg(char **matrice)
{
	unsigned int	i;
	unsigned int	x;

	i = 0;
	while (matrice[i])
	{
		x = 0;
		while (matrice[x])
		{
			// if (matrice[i][x] > '9' || matrice[i][x] < '0')
			// 	free_and_exit(matrice);
			if (ft_atoi(matrice[i]) == -1)
				free_and_exit(matrice);
			x++;
		}
		i++;
	}
	check_duplication(matrice);
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
	verif_arg(pile.matrice_a);
	size = count_len_matrice(pile.matrice_a);
	if (argc <= 4)
		deal_with_three_arg(pile);
	else if (argc <= 6)
		deal_with_five_arg(pile);
	else if (argc <= 101)
		deal_with_five_hundred(pile, size);
	else
		deal_with_five_hundred(pile, size);
}