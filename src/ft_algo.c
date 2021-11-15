#include "../main.h"

char	**swap_a(char **matrice)
{
	char	*tmp;

	tmp = matrice[0];
	matrice[0] = matrice[1];
	matrice[1] = tmp;
	printf("sa\n");
	return (matrice);
}

char	**rotate(char **matrice, char *cmd)
{
	char			*tmp;
	unsigned int	i;

	tmp = matrice[0];
	i = 0;
	while (i + 1 < count_len_matrice(matrice))
	{
		matrice[i] = matrice[i + 1];
		i++;
	}
	matrice[i] = tmp;
	printf("%s\n", cmd);
	return (matrice);
}

char	**push_begin(char **matrice, char *to_add)
{
	char	**to_return;
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

int	max_arr(char **matrice)
{
	unsigned int	i;
	int				max;

	i = 0;
	max = -1;
	while (matrice[i])
	{
		if (atoi(matrice[i]) > max || max == -1)
			max = atoi(matrice[i]);
		i++;
	}
	return (max);
}

int	min_arr(char **matrice)
{
	unsigned int	i;
	int				min;

	i = 0;
	min = -1;
	while (matrice[i])
	{
		if (atoi(matrice[i]) < min || min == -1)
			min = atoi(matrice[i]);
		i++;
	}
	return (min);
}

t_pile	ft_algo(t_pile pile)
{

	if (max_arr(pile.matrice_a) == atoi(pile.matrice_a[0]))
		pile.matrice_a = rotate(pile.matrice_a, "ra");
	else
		pile = push_b(pile.matrice_a, pile.matrice_b);
	return (pile);
}