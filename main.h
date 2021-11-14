/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 13:25:51 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/14 13:25:52 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_loop{
	int				i;
	char			**to_return;
	unsigned int	x;
	unsigned int	last_index;
}				t_loop;

unsigned int	count_len_matrice(char **matrice);
unsigned int	count_len_next(char *str);
void			read_that_matrice(char **matrice);
unsigned int	count_occ(char *str, char occ);
char			*ft_substr(char *str, unsigned int start, unsigned int end);
char			**push_arr(char **nbr, char *to_add);
void			free_that_matrice(char **matrice);
char			**parse_argv(int argc, char **argv, char **nbr);
unsigned int	is_sorted(char	**stack);

#endif