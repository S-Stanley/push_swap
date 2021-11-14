unsigned int	count_len_next(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] || str[i] == ' ')
		i++;
	return (i);
}
