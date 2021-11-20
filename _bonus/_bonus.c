#include "../main.h"
#include "stdio.h"
#include "_bonus.h"

unsigned int	get_size_concat(char *s1, char *s2)
{
	if (!s1)
		return (ft_strlen(s2) + 1);
	if (!s2)
		return (ft_strlen(s1) + 1);
	return (ft_strlen(s1) + ft_strlen(s2) + 1);
}

char	*ft_concat(char *buffer, char *new_buffer)
{
	unsigned int	i;
	unsigned int	x;
	char			*to_return;

	i = 0;
	to_return = malloc(sizeof(char) * (ft_strlen(buffer) + ft_strlen(new_buffer) + 1));
	if (!to_return)
	{
		free(buffer);
		free(new_buffer);
		exit(0);
	}
	if (buffer)
	{
		while (buffer[i])
		{
			to_return[i] = buffer[i];
			i++;
		}
	}
	x = 0;
	while (new_buffer[x])
	{
		to_return[i] = new_buffer[x];
		x++;
		i++;
	}
	to_return[i] = 0;
	free(buffer);
	free(new_buffer);
	return (to_return);
}

char	*get_commandes(unsigned int	size)
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
			break;
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

int	main(int argc, char **argv)
{
	unsigned int 	size;
	char 			**cmd;
	char			*buffer;
	t_pile			pile;

	pile.matrice_a = NULL;
	pile.matrice_b = NULL;
	pile.matrice_a = parse_argv(argc, argv, pile.matrice_a);
	if (argc > 2)
		verif_arg(pile.matrice_a);
	size = 1;
	buffer = get_commandes(size);
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
	return (0);
}