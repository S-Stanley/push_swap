#include "../main.h"
#include "stdio.h"
#include "_bonus.h"

char	*ft_concat(char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	x;
	char			*to_return;

	i = 0;
	to_return = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
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

int	main(int argc, char **argv)
{
	char			*buffer;
	unsigned int	readed;
	unsigned int 	size;
	char			*new_buffer;

	buffer = NULL;
	size = 40;
	while (1)
	{
		new_buffer = malloc(sizeof(char) * (ft_strlen(buffer) + size));
		if (!new_buffer)
			return (0);
		readed = read(STDIN_FILENO, new_buffer, size - 1);
		new_buffer[size] = 0;
		if (readed == 0)
			break;
		buffer = ft_concat(buffer, new_buffer);
	}

	char **to_print = ft_split(buffer, '\n');
	int i = 0;
	while (to_print[i])
	{
		printf("**%s**\n", to_print[i]);		
		i++;
	}
	free_that_matrice(to_print);
	return (0);
}