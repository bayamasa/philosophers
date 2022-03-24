/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:38:46 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/24 13:40:07 by mhirabay         ###   ########.fr       */
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
# include "limits.h"

# define NUMBER_OF_PHILOSOPHERS 1
# define TIME_TO_DIE 2
# define TIME_TO_EAT 3
# define TIME_TO_SLEEP 4
# define TIMES_PHILO_MUST_EAT 5

# define STR_BUFF_SIZE 1000000
# define PHILO_COUNT_MAX 2000
# define ERROR "Error\n"
# define ARGS_ERROR "args error\n"
# define MALLOC_ERROR "malloc error\n"
# define CREATE_THREAD_ERROR "create thread error\n"
# define JOIN_THREAD_ERROR "join thread error\n"
# define DETACH_THREAD_ERROR "detach thread error\n"
# define MMUTEX_DESTROY_ERROR "monitor mutex destroy error\n"
# define FMUTEX_DESTROY_ERROR "fork mutex destroy error\n"
# define CANNOT_TAKEN_FORK "cannot taken the forks\n"
# define MUTEX_INIT_ERROR "mutex init error\n"
# define LOCK_ERROR "lock error\n"
# define UNLOCK_ERROR "unlock error\n"

typedef struct s_philo_config {
	size_t			fork_count;
	bool			*is_fork_taken;
	size_t			eat_t;
	size_t			sleep_t;
	pthread_mutex_t	*fork_mutex;
}	t_philo_config;

typedef struct s_public_config
{
	bool			eat_limit_exist;
	bool			eat_limit_surpassed;
	size_t			eat_limit;
	size_t			philo_count;
	size_t			eat_count;
	size_t			die_t;
	bool			is_anyone_dead;
	pthread_mutex_t	m_mutex;
}	t_public_config;

typedef struct s_philo_attr
{
	size_t			index;
	size_t			num;
	size_t			start_t;
	size_t			ate_t;
	pthread_t		thread;
	t_philo_config	*phc;
	t_public_config	*pc;
}	t_philo_attr;

typedef struct s_monitor_attr
{
	t_philo_attr	**ph_attr;
	t_public_config	*pc;
}	t_monitor_attr;

typedef struct s_sim_stat {
	t_philo_attr	**ph_attr;
	t_monitor_attr	*m_attr;
	t_philo_config	*ph_config;
	t_public_config	*pub_config;
}	t_sim_stat;

// philo_utils.c
int			ft_isdigit(int c);
size_t		ft_atoi_error(const char *str, int *status);
int			ft_isspace(char a);
long long	ft_strtoll(const char *str, int *status);
void		ft_putstr_fd(char *s, int fd);
size_t		ft_atoi(const char *str);

// philo_utils_2.c
size_t		ft_strlen(const char *str);
size_t		gettime(void);
void		get_forks_position(\
			size_t fork_count, size_t p_i, size_t *r, size_t *l);
bool		is_eat_limit_surpassed(t_public_config *pc);
int			ft_isspace(char a);

// philo_utils_3.c
bool		lock(pthread_mutex_t *mutex);
bool		unlock(pthread_mutex_t *mutex);
void		*ft_memset(void *buf, int ch, size_t n);
bool		finish_thread(t_philo_attr *ph);
bool		finish_thread_when_taken_one_fork(t_philo_attr *ph);

// error_handling.c
bool		abort_philo_msg(char *msg);
bool		abort_philo_msg_with_free(char *msg, t_sim_stat *ph);
void		free_all(t_sim_stat *s);

// args_handling.c
bool		check_args(int argc, const char **argv);
void		validate_philo_count(const char *str, int *status);
void		validate_time(const char *str, int *status);
void		validate_eat_limit(const char *str, int *status);

// init.c
bool		init(t_sim_stat *s, const char *argv[]);

// init_utils.c
bool		init_philo_attr(t_sim_stat *s, const char *argv[]);
bool		init_monitor_attr(t_sim_stat *s);
bool		init_pub_config(t_public_config *pc, const char *argv[]);
bool		init_philo_config(t_philo_config *ph, const char *argv[]);
bool		init_all_config(t_sim_stat *s, const char *argv[]);

// debug.c
void		print_all_fork_status(t_philo_attr *ph);
void		debug_thread_start(size_t count);
void		debug_all_fork_normal(t_philo_attr *ph);
void		print_args(t_philo_attr *ph);
void		print_gettime(size_t time);

// simulation.c
bool		start_simulation(t_sim_stat *a);
bool		is_anyone_dead(t_public_config *pc);

// print_act.c
bool		print_act_take_fork(t_philo_attr *ph);
bool		print_act_eating(t_philo_attr *ph);
bool		print_act_sleeping(t_philo_attr *ph);
bool		print_act_thinking(t_philo_attr *ph);
bool		print_act_died(size_t philo);

// act.c
bool		take_forks(t_philo_attr *ph);
bool		take_down_forks(t_philo_attr *ph);
bool		eating(t_philo_attr *ph);
bool		sleeping(t_philo_attr *ph);
bool		thinking(t_philo_attr *ph);

// philo_act_alone.c
void		*take_fork(t_philo_attr *ph);

// monitor.c
void		*monitor_philo(void *attr);
bool		is_philo_dead(t_monitor_attr *s, size_t philo_i);

void		xusleep(size_t eat_t);

#endif
