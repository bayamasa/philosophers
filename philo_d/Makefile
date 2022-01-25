# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 16:30:33 by mhirabay          #+#    #+#              #
#    Updated: 2022/01/25 22:25:37 by mhirabay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := philo


SRCDIR := ./src/
SRCNAME = 	main.c \
			args_handling.c \
			error_handling.c \
			philo_utils.c \
			philo_utils_2.c \

SRCS = $(addprefix $(SRCDIR), $(SRCNAME))

OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Werror -Wextra
INC = -I ./includes/
all: ${NAME}

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(INC) $(OBJS) -o $(NAME)

%.o : %.c
		${CC} ${CFLAGS} $(INC) -c $< -o $@
clean: 
	${RM} ${OBJS}
fclean: clean
	${RM} ${NAME} 
re:		fclean all

.PHONY: all clean fclean re .c.o
