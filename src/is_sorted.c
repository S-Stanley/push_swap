#include "../main.h"

unsigned int	is_sorted(char	**stack)
{
	unsigned int	i;

	if (count_len_matrice(stack) <= 1)
		return (1);
	i = 1;
	while (stack[i])
	{
		if (atoi(stack[i]) < atoi(stack[i - 1]))
			return (0);
		i++;
	}
	return (1);
}