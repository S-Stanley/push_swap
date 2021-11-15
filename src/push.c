/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 01:55:55 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/15 01:55:56 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

char	**push_begin(char **matrice, char *to_add)
{
	char			**to_return;
	unsigned int	i;

	i = 0;
	to_return = malloc(sizeof(char *) * (count_len_matrice(matrice) + 2));
	if (!to_return)
		return (NULL);
	to_return[i] = to_add;
	(void)to_add;
	if (matrice)
	{
		while (matrice[i])
		{
			to_return[i + 1] = matrice[i];
			i++;
		}
	}
	to_return[i + 1] = 0;
	// free_that_matrice(matrice);
	return (to_return);
}

void	clean_and_exit(char **a, char **b)
{
	free_that_matrice(a);
	free_that_matrice(b);
	exit(0);
}

t_pile	push_b(char **a, char **b)
{
	t_pile			to_return;
	char			**new_a;
	unsigned int	i;

	b = push_begin(b, a[0]);
	if (!b)
		clean_and_exit(a, b);
	new_a = malloc(sizeof(char *) * (count_len_matrice(a) + 1));
	if (!a)
		clean_and_exit(a, b);
	i = 1;
	while (a[i])
	{
		new_a[i - 1] = a[i];
		i++;
	}
	new_a[i - 1] = 0;
	to_return.matrice_a = new_a;
	to_return.matrice_b = b;
	printf("pb\n");
	return (to_return);
}

t_pile	push_a(char **a, char **b)
{
	char			**new_b;
	unsigned int	i;
	t_pile			to_return;

	a = push_begin(a, b[0]);
	if (!a)
		clean_and_exit(b, a);
	new_b = malloc(sizeof(char *) * (count_len_matrice(b) + 1));
	if (!new_b)
		clean_and_exit(b, a);
	i = 1;
	while (b[i])
	{
		new_b[i - 1] = b[i];
		i++;
	}
	new_b[i - 1] = 0;
	to_return.matrice_a = a;
	to_return.matrice_b = new_b;
	printf("pa\n");
	return (to_return);
}
