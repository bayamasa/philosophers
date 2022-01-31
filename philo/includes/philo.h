/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:38:46 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/31 23:53:15 by mhirabay         ###   ########.fr       */
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
// TODO: 後で消すこと
# include <errno.h>


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
# define DETACH_THREAD_ERROR "detach thread error\n"
# define MUTEX_DESTROY_ERROR "mutex destroy error\n"
# define CANNOT_TAKEN_FORK "cannot taken the forks\n"
# define MUTEX_INIT_ERROR "mutex init error\n"

typedef struct s_philo_attr
{
	size_t			num;
	size_t			eat_t;
	size_t			die_t;
	size_t			sleep_t;
	size_t			start_t;
	size_t			ate_t;
	pthread_t		thread;
}	t_philo_attr;

typedef struct s_monitor_attr
{
	pthread_mutex_t	mutex;
}	t_monitor_attr;

typedef struct s_sim_stat {
	size_t			philo_count;
	size_t			eat_limit;
	size_t			fork_count;
	int				*is_fork_taken;
	t_philo_attr	*p_attr;
	size_t			thread_i;
	pthread_mutex_t	*fork_mutex;
	t_monitor_attr	m_attr;
	int				is_anyone_dead;
	size_t			eat_count;
	int				eat_limit_flag;
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
void		get_forks_position(\
			size_t fork_count, size_t p_i, size_t *r, size_t *l);
bool		is_eat_limit_surpassed(t_sim_stat *s);

// philo_utils_3.c
bool		lock(pthread_mutex_t mutex);
bool		unlock(pthread_mutex_t mutex);
bool		is_forks_unused(t_sim_stat *t, size_t r, size_t l);
void		*ft_memset(void *buf, int ch, size_t n);

// error_handling.c
bool		abort_philo_msg(char *msg);
bool		abort_philo_msg_with_free(char *msg, t_sim_stat *s);
void		free_all(t_sim_stat *s);

// args_handling.c
bool		check_args(int argc, const char **argv);
void		validate_philo_count(const char *str, int *status);
void		validate_time(const char *str, int *status);
void		validate_eat_limit(const char *str, int *status);

// init.c
bool		init(t_sim_stat *s, const char *argv[]);
// debug.c
void		print_all_fork_status(t_sim_stat *a);
void		debug_thread_start(size_t count);
void		print_act_takedown_fork(size_t philo, size_t time);
void		debug_all_fork_normal(t_sim_stat *s);
void		print_args(t_sim_stat *s);

// simulation.c
bool		start_simulation(t_sim_stat *a);
bool		is_anyone_dead(t_sim_stat *s);

// print_act.c
bool		print_act_take_fork(t_sim_stat *s, size_t philo, size_t time);
bool		print_act_eating(\
			t_sim_stat *s, size_t philo, size_t time, size_t philo_i);
bool		print_act_sleeping(t_sim_stat *s, size_t philo, size_t time);
bool		print_act_thinking(t_sim_stat *s, size_t philo, size_t time);
bool		print_act_died(size_t philo, size_t time);

// act.c
bool		take_forks(t_sim_stat *a, size_t philo_i);
bool		take_down_forks(t_sim_stat *a, size_t philo_i);
bool		eating(t_sim_stat *a, size_t philo_i);
bool		sleeping(t_sim_stat *a, size_t philo_i);
bool		thinking(t_sim_stat *a, size_t philo_i);

// monitor.c
void		*monitor_philo(void *attr);
bool		is_philo_dead(t_sim_stat *s, size_t philo_i);

#endif
