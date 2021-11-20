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

int	main(int argc, char **argv)
{
	unsigned int 	size;
	char 			**to_print;
	char			*buffer;

	size = 1;
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