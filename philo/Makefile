# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 13:21:26 by mhirabay          #+#    #+#              #
#    Updated: 2022/03/24 13:56:31 by mhirabay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	:= philo
SRCDIR 	:= ./src/
SRCNAME	:=	philo_act.c \
			philo_act_alone.c \
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
CFLAGS	:= -Wall -Werror -Wextra -pthread
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

.PHONY: all clean fclean re
