#include "../main.h"

char	*ft_strdup(char *str)
{
	unsigned int	i;
	char		*to_return;

	to_return = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!to_return)
		return (NULL);
	i = 0;
	while (str[i])
	{
		to_return[i] = str[i];
		i++;
	}
	to_return[i] = 0;
	return (to_return);
}
