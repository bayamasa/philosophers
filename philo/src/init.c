/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 09:09:23 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/31 23:18:12 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	init_philo_attr(t_sim_stat *s, const char *argv[])
{
	size_t	i;
	int		status;

	i = 0;
	status = true;
	s->p_attr = (t_philo_attr *)malloc(sizeof(t_philo_attr) * s->philo_count);
	if (s->p_attr == NULL)
		return (false);
	while (i < s->philo_count)
	{
		s->p_attr[i].num = i + 1;
		s->p_attr[i].die_t = ft_atoi_error(argv[TIME_TO_DIE], &status);
		s->p_attr[i].eat_t = ft_atoi_error(argv[TIME_TO_EAT], &status);
		s->p_attr[i].sleep_t = ft_atoi_error(argv[TIME_TO_SLEEP], &status);
		// TODO: 下2つは必要かどうかわからんけど一応
		s->p_attr[i].start_t = 0;
		s->p_attr[i].ate_t = 0;
		i++;
	}
	return (true);
}

bool	init_thread(t_sim_stat *s)
{
	size_t	i;

	if (pthread_mutex_init(&(s->m_attr.mutex), NULL) == -1)
		return (abort_philo_msg(MUTEX_INIT_ERROR));
	s->fork_mutex = (pthread_mutex_t *) \
		malloc(sizeof(pthread_mutex_t) * s->fork_count);
	if (s->fork_mutex == NULL)
		return (abort_philo_msg(MALLOC_ERROR));
	i = 0;
	while (i < s->fork_count)
	{
		if (pthread_mutex_init(&(s->fork_mutex[i]), NULL) == -1)
			return (abort_philo_msg_with_free(MUTEX_INIT_ERROR, s));
		i++;
	}
	return (true);
}


bool	init(t_sim_stat *s, const char *argv[])
{
	int		status;

	s->philo_count = ft_atoi_error(argv[NUMBER_OF_PHILOSOPHERS], &status);
	s->fork_count = s->philo_count;
	if (!init_thread(s))
		return (false);
	//TODO: statusが必要ないatoi or strtollを作る
	status = true;
	if (!init_philo_attr(s, argv))
		return (abort_philo_msg(MALLOC_ERROR));
	s->eat_count = 0;
	if (argv[TIMES_PHILO_MUST_EAT] != NULL)
	{
		s->eat_limit_flag = true;
		s->eat_limit = ft_atoi_error(argv[TIMES_PHILO_MUST_EAT], &status);
	}
	else
		s->eat_limit_flag = false;
	s->is_fork_taken = (int *)malloc(sizeof(int) * s->fork_count);
	if (s->is_fork_taken == NULL)
		return (abort_philo_msg_with_free(MALLOC_ERROR, s));
	// 最初に全部0埋め
	// TODO: overflow考慮する。
	ft_memset(s->is_fork_taken, false, sizeof(int) * s->fork_count);
	s->is_anyone_dead = false;
	return (true);
}
