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
FLAGS = -Wall -Wextra -Werror -MMD
RM = rm -rf
include src.mk
# OBJS=$(SRCS:.c=.o)
OBJDIR=./obj
OBJS:= $(SRCS:%.c=$(OBJDIR)/%.o)
DEP=$(OBJS:.o=.d)
# OBJS=$(addprefix $(SRCS), $(OBJS_RUN))
GREEN='\033[0;32m'
BLUE='\033[0;34m'
RED='\033[0;31m'
WHITE='\033[0;37m'

-include $(DEP)

all:	$(NAME)

# .c.o:
$(OBJDIR)/%.o: %.c
	@clang $(FLAGS) -c $< -o $@
	@echo $(WHITE)".\c"

$(NAME):	$(OBJS)
	@clang $(FLAGS) $(OBJS) -o $(NAME)
	@echo $(GREEN)"\npush_swap has been created"

clean:	cleandep
	@echo $(RED)"Deleting .c files"
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@echo $(RED)$(NAME) "has been deleted"

cleandep:
	@echo $(RED)"Deleting .d files.."
	@rm -rf $(DEP)

re:	fclean	all

.PHONY: all fclean clean re cleandep