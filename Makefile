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
FLAGS = -Wall -Wextra -Werror -MMD -ggdb3
RM = rm -rf
include src.mk
# OBJS=$(SRCS:.c=.o)
OBJDIR=obj
OBJS= $(SRCS:%.c=$(OBJDIR)/%.o)
# OBJS:= $(SRCS:.c=.o)
DEP=$(OBJS:.o=.d)
# OBJS=$(addprefix $(SRCS), $(OBJS_RUN))
GREEN='\033[0;32m'
BLUE='\033[0;34m'
RED='\033[0;31m'
WHITE='\033[0;37m'

-include $(DEP)

all:	$(NAME)

$(OBJDIR):
	$(shell mkdir obj)

$(OBJDIR)/%.o: %.c
# .c.o:
# clang $(FLAGS) -c $< -o $(<:.c=.o)
	@clang $(FLAGS) -c -o $(OBJDIR)/$(@F) $<
	@echo $(WRITE)"Compiling" $<

$(NAME): 	$(OBJDIR) $(OBJS)
	$(CC) obj/*.o -o push_swap
# $(CC) $(FLAGS) $(OBJS) -o $(NAME)
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

.PHONY: all fclean clean re cleandep bonus