#include "../main.h"

void	read_that_matrice(char **matrice)
{
	unsigned int	i;

	i = 0;
	if (!matrice)
		return ;
	while (matrice[i])
	{
		printf("%s\n", matrice[i]);
		i++;
	}
}