# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 13:21:26 by mhirabay          #+#    #+#              #
#    Updated: 2022/03/21 20:32:04 by mhirabay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	:= philo
SRCDIR 	:= ./src/
SRCNAME	:=	philo_act.c \
			args_handling.c \
			debug.c \
			error_handling.c \
			init.c \
			init_utils.c \
			main.c \
			philo_utils.c \
			philo_utils_2.c \
			philo_utils_3.c \
			print_philo_act.c \
			simulation.c \
			monitor.c \

SRCS	:= $(addprefix $(SRCDIR), $(SRCNAME))
OBJSDIR	:= ./obj/
OBJS 	:= $(addprefix $(OBJSDIR), $(SRCNAME:%.c=%.o))

CC		:= gcc 
CFLAGS	:= -Wall -Werror -Wextra -g -pthread
DEBUG	:= -g -fsanitize=thread
INC		:= -I ./philo/includes/
RM		:= rm -rf

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(INC) $^ -o $@

$(OBJSDIR)%.o : $(SRCDIR)%.c
	@if [ ! -d $(OBJSDIR) ]; then mkdir $(OBJSDIR); fi
	${CC} ${CFLAGS} $(INC) -c $< -o $@

clean: 
	$(RM) $(OBJSDIR)

fclean: clean
	${RM} ${NAME} 
re:	fclean all

debug:	CFLAGS += $(DEBUG)
debug:	re

.PHONY: all clean fclean re debug
