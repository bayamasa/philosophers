/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 09:32:11 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/31 21:22:07 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*start_philo_act(void *stat)
{
	t_sim_stat	*s;
	size_t		thread_i;

	s = (t_sim_stat *)stat;
	thread_i = s->thread_i;
	while (true)
	{
		if (!take_forks(s, thread_i))
			break ;
		if (!eating(s, thread_i))
			break ;
		if (!sleeping(s, thread_i))
			break ;
		if (!thinking(s, thread_i))
			break ;
	}
	return (0);
}

bool	is_anyone_dead(t_sim_stat *s)
{
	if (s->is_anyone_dead)
		return (true);
	return (false);
}

bool	start_simulation(t_sim_stat *s)
{
	size_t			i;
	pthread_t		m_thread;

	i = 0;
	while (i < s->philo_count)
	{
		usleep(20);
		s->thread_i = i;
		s->p_attr[i].ate_t = gettime();
		if (pthread_create(&(s->p_attr[i].thread), \
			NULL, start_philo_act, s) != 0)
			return (abort_philo_msg_with_free(CREATE_THREAD_ERROR, s));
		i++;
	}
	if (pthread_create(&m_thread, NULL, monitor_philo, s) != 0)
		return (abort_philo_msg_with_free(CREATE_THREAD_ERROR, s));
	if (pthread_join(m_thread, NULL) != 0)
		return (abort_philo_msg_with_free(JOIN_THREAD_ERROR, s));
	i = 0;
	while (i < s->philo_count)
	{
		if (pthread_detach(s->p_attr[i].thread) != 0)
			return (abort_philo_msg_with_free(DETACH_THREAD_ERROR, s));
		i++;
	}
	if (pthread_mutex_destroy(&(s->mutex)) != 0)
		return (abort_philo_msg_with_free(JOIN_THREAD_ERROR, s));
	return (true);
}
