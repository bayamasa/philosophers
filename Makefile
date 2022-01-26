# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 13:21:26 by mhirabay          #+#    #+#              #
#    Updated: 2022/01/25 23:47:39 by mhirabay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	:= philo
DIR 	:= ./philo/

EXEC 	:= $(addprefix $(DIR), $(NAME))

SRCDIR 	:= $(addprefix $(DIR), src/)
SRCS 	:= $(shell cd $(SRCDIR) && echo *.c)

OBJSDIR	:= $(addprefix $(DIR), obj/)
OBJS 	:= $(addprefix $(OBJSDIR), $(SRCS:%.c=%.o))

CC		:= gcc 
CFLAGS	:= -Wall -Werror -Wextra
DEBUG	:= -g -fsanitize=thread
INC		:= -I ./philo/includes/
RM		:= rm -rf
all: ${EXEC}

$(EXEC) : $(OBJS)
	$(CC) $(CFLAGS) $(INC) $^ -o $@

$(OBJSDIR)%.o : $(SRCDIR)%.c
	@if [ ! -d $(OBJSDIR) ]; then mkdir $(OBJSDIR); fi
	${CC} ${CFLAGS} $(INC) -c $< -o $@

clean: 
	$(RM) $(OBJSDIR)

fclean: clean
	${RM} ${EXEC} 
re:	fclean all

debug:	CFLAGS += $(DEBUG)
debug:	re

.PHONY: all clean fclean re debug
