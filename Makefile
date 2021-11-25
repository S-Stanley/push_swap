# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/14 19:54:12 by sserbin           #+#    #+#              #
#    Updated: 2021/11/14 19:54:13 by sserbin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC= main.c \
	src/parse_argv.c \
	src/is_sorted.c \
	src/algo.c \
	src/push.c \
	src/rotate.c \
	src/swap_a.c \
	src/verif_arguments.c \
	src/utils_algo.c \
	src/clean.c \
	utils/count_len_matrice.c \
	utils/count_len_next.c \
	utils/count_occurence.c \
	utils/free_that_matrice.c \
	utils/ft_substr.c \
	utils/push_arr.c \
	utils/read_that_matrice.c \
	utils/arr.c \
	utils/ft_itoa.c \
	utils/ft_atoi.c \
	utils/ft_strlen.c \
	utils/print_text.c \
	utils/ft_strdup.c
OBJS = $(SRC:.c=.o)
NAME = push_swap
CC = clang
FLAGS = -Wall -Wextra -Werror
RM = rm -rf
BONUS_SRC = src/parse_argv.c \
	src/is_sorted.c \
	src/algo.c \
	src/push.c \
	src/rotate.c \
	src/swap_a.c \
	src/clean.c \
	src/verif_arguments.c \
	src/utils_algo.c \
	utils/count_len_matrice.c \
	utils/count_len_next.c \
	utils/count_occurence.c \
	utils/free_that_matrice.c \
	utils/ft_substr.c \
	utils/push_arr.c \
	utils/read_that_matrice.c \
	utils/arr.c \
	utils/ft_itoa.c \
	utils/ft_atoi.c \
	utils/ft_strlen.c \
	utils/print_text.c \
	utils/ft_strdup.c \
	_bonus/_bonus_ft_strjoin.c \
	_bonus/_bonus_ft_split.c \
	_bonus/_bonus.c \
	_bonus/_bonus_push.c
BONUS_OBJS=$(BONUS_SRC:.c=.o)
BONUS_NAME= checker

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

re: clean all

fclean: clean
	$(RM) $(NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(FLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

bonus: $(NAME) $(BONUS_NAME)

bonus_clean:
	$(RM) $(BONUS_OBJS)

bonus_re: bonus_clean bonus

bonus_fclean: bonus_clean
	$(RM) $(BONUS_NAME)

.PHONY: all clean re fclean bonus bonus_clean bonus_re bonus_fclean