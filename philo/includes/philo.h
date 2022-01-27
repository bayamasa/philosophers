/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:38:46 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/27 16:42:26 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdbool.h>
# include <string.h>
# include <sys/time.h>

# define NUMBER_OF_PHILOSOPHERS 1
# define TIME_TO_DIE 2
# define TIME_TO_EAT 3
# define TIME_TO_SLEEP 4
# define TIMES_PHILO_MUST_EAT 5

# define STR_BUFF_SIZE 1000000
# define USEC_DIGITS 1000000
# define ERROR "Error\n"
# define ARGS_ERROR "args error\n"
# define MALLOC_ERROR "malloc error\n"
# define CREATE_THREAD_ERROR "create thread error\n"
# define JOIN_THREAD_ERROR "join thread error\n"
# define CANNOT_TAKEN_FORK "cannot taken the forks\n"
# define MUTEX_INIT_ERROR "mutex init error\n"

// TODO: philo用の構造体を作る

typedef struct s_philo_attr
{
	size_t			num;
	size_t			eat_t;
	size_t			die_t;
	size_t			sleep_t;
	size_t			start_t;
	size_t			ate_t;
}	t_philo_attr;

typedef struct s_sim_stat {
	size_t			philo_count;
	size_t			meal_limits;
	size_t			fork_count;
	int				*is_fork_taken;
	t_philo_attr	*p_attr;
	size_t			thread_i;
	pthread_mutex_t	mutex;
}	t_sim_stat;



// philo_utils.c
int			ft_isdigit(int c);
size_t		ft_atoi_error(const char *str, int *status);
int			ft_isspace(char a);
long long	ft_strtoll(const char *str, int *status);
void		ft_putstr_fd(char *s, int fd);

// philo_utils_2.c
size_t		ft_strlen(const char *str);
size_t		gettime(void);

// error_handling.c
int			abort_philo_msg(char *msg);
int			abort_philo_msg_with_free(char *msg, t_sim_stat *a);

// args_handling.c
int			check_args(int argc, const char **argv);
void		validate_philo_count(const char *str, int *status);
void		validate_time(const char *str, int *status);
void		validate_eat_limit(const char *str, int *status);

// init.c
int			init(t_sim_stat *s, const char *argv[]);
// debug.c
void		print_all_fork_status(t_sim_stat *a);
void		debug_thread_start(size_t count);

// simulation.c
int			start_simulation(t_sim_stat *a);

// print_act.c
void		print_act_take_fork(size_t philo, size_t time);
void		print_act_eating(size_t philo, size_t time);
void		print_act_sleeping(size_t philo, size_t time);
void		print_act_thinking(size_t philo, size_t time);
void		print_act_died(size_t philo, size_t time);

// act.c
int			take_fork(t_sim_stat *a, size_t philo_i);
int			take_down_fork(t_sim_stat *a, size_t philo_i);
void		eating(t_sim_stat *a, size_t philo_i);
void		sleeping(t_sim_stat *a, size_t philo_i);
void		thinking(t_sim_stat *a, size_t philo_i);

#endif
