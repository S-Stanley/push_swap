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

NAME = push_swap
CC = clang
FLAGS = -Wall -Wextra -Werror
RM = rm -rf
include src.mk
OBJS=$(SRCS:.c=.o)
OBJDIR=./utils/
# OBJS=$(addprefix $(SRCS), $(OBJS_RUN))
GREEN='\033[0;32m'
BLUE='\033[0;34m'
RED='\033[0;31m'
WHITE='\033[0;37m'

.c.o:	
	@clang $(FLAGS) -c $< -o $(<:.c=.o)
	@echo $(WHITE) "."

all:	$(NAME)

$(NAME):	$(OBJS)
	@clang $(FLAGS) $(OBJS) -o $(NAME)
	@echo $(GREEN)"push_swap has been created"

clean:
	@echo $(RED) "deleting files"
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@echo $(RED) $(NAME) "has been deleted"

re:	fclean	all

.PHONY: all fclean clean re