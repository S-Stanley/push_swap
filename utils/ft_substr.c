#include "../main.h"

char	*ft_substr(char *str, unsigned int start, unsigned int end)
{
	char			*to_return;
	unsigned int	i;

	to_return = malloc(sizeof(char) * (end - start + 2));
	if (!str || !to_return)
		return (NULL);
	i = 0;
	while (start <= end)
	{
		if (str[start] != ' ')
		{
			to_return[i] = str[start];
			i++;
		}
		start++;
	}
	to_return[i] = 0;
	return (to_return);
}
