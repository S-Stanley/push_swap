#include "../main.h"
#include "stdio.h"
#include "_bonus.h"

unsigned int	get_size_concat(char *s1, char *s2)
{
	if (!s1)
		return (ft_strlen(s2) + 1);
	if (!s2)
		return (ft_strlen(s1) + 2);
	return (ft_strlen(s1) + ft_strlen(s2) + 1);
}

char	*ft_concat(char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	x;
	char			*to_return;

	i = 0;
	to_return = malloc(sizeof(char) * get_size_concat(s1, s2));
	if (!to_return)
	{
		free(s1);
		free(s2);
		exit(0);
	}
	if (s1)
	{
		while (s1[i])
		{
			to_return[i] = s1[i];
			i++;
		}
	}
	x = 0;
	while (s2[x])
	{
		to_return[i] = s2[x];
		x++;
		i++;
	}
	to_return[i] = 0;
	free(s1);
	free(s2);
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
		new_buffer = malloc(sizeof(char) * (ft_strlen(buffer) + size));
		if (!new_buffer)
			return (0);
		readed = read(STDIN_FILENO, new_buffer, size - 1);
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

int	main(int argc, char **argv)
{
	unsigned int 	size;
	char 			**to_print;
	char			*buffer;

	size = 40;
	buffer = get_commandes(size);
	if (buffer)
	{
		to_print = ft_split(buffer, '\n');
		int i = 0;
		while (to_print[i])
		{
			printf("**%s**\n", to_print[i]);		
			i++;
		}
		free_that_matrice(to_print);
	}
	free(buffer);
	return (0);
}