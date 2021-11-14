#include "../main.h"

char	**push_arr(char **nbr, char *to_add)
{
	char			**to_return;
	unsigned int	i;

	to_return = malloc(sizeof(char *) * (count_len_matrice(nbr) + 2));
	if (!to_return)
	{
		printf("probleme allocation to_return in push_arr");
		exit(0);
	}
	i = 0;
	if (nbr)
	{
		while (nbr[i])
		{		
			to_return[i] = nbr[i];
			i++;
		}
		free(nbr);
	}
	to_return[i] = to_add;
	to_return[++i] = 0;
	return (to_return);
}