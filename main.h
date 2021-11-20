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

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_loop{
	int				i;
	char			**to_return;
	unsigned int	x;
	unsigned int	last_index;
}				t_loop;

typedef struct s_pile{
	char	**matrice_a;
	char	**matrice_b;
}				t_pile;

unsigned int	count_len_matrice(char **matrice);
unsigned int	count_len_next(char *str);
void			read_that_matrice(char **matrice);
unsigned int	count_occ(char *str, char occ);
char			*ft_substr(char *str, unsigned int start, unsigned int end);
char			**push_arr(char **nbr, char *to_add);
void			free_that_matrice(char **matrice);
char			**parse_argv(int argc, char **argv, char **nbr);
unsigned int	is_sorted(char	**stack);
int				min_arr(char **matrice);
int				max_arr(char **matrice);
char			**rotate(char **matrice, char *cmd);
t_pile			push_b(char **a, char **b);
t_pile			push_a(char **a, char **b);
void			read_that_matrice(char **matrice);
char			**swap(char **matrice, char *cmd);
char			**rotate_reverse(char **matrice, char *cmd);
unsigned int	is_sorted_reverse(char **stack);
char			*ft_itoa(int n);
unsigned int	ft_strlen(char *str);
long long		ft_atoi(char *str);
void			print_text(char *str);
unsigned int	find_in_arr(char **matrice, int to_find);
void			verif_arg(char **matrice);
t_pile			deal_with_five_arg(t_pile pile);
void			deal_with_five_hundred(t_pile pile, unsigned int size);
t_pile			deal_with_three_arg(t_pile pile);
char			**find_the_lowers(char **matrice, int nb_rotation);
unsigned int	should_start_with_rotate(char **matrice, char **grp);
unsigned int	get_index(char **matrice, int value);
unsigned int	is_the_right_place(t_pile pile);
unsigned int	should_rotate(char **matrice, unsigned int index);

#endif