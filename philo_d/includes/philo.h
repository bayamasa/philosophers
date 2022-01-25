/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:38:46 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/25 16:29:20 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdbool.h>

# define STR_BUFF_SIZE 1000000
# define ERROR "Error\n"
# define ARGS_ERROR "args error\n"

typedef struct s_status {
	size_t	philo_num;
	size_t	eat_t;
	size_t	die_t;
	size_t	sleep_t;
	size_t	meal_limits;
}	t_status;


// philo_utils.c
int			ft_isdigit(int c);
size_t		ft_atoi_error(const char *str, int *status);
int			ft_isspace(char a);
long long	ft_strtoll(const char *str, int *status);
void		ft_putstr_fd(char *s, int fd);

// error_handling.c
int			abort_philo_msg(char *msg);


#endif
