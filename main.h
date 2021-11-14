#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


unsigned int	count_len_matrice(char **matrice);
unsigned int	count_len_next(char *str);
void			read_that_matrice(char **matrice);
unsigned int	count_occ(char *str, char occ);
char			*ft_substr(char *str, unsigned int start, unsigned int end);
char			**push_arr(char **nbr, char *to_add);