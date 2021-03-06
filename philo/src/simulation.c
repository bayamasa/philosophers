/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 09:32:11 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/24 10:20:55 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	xusleep(size_t time)
{
	size_t	start_time;

	start_time = gettime();
	while (gettime() - start_time < time)
		usleep(100);
}

void	*start_philo_act(void *ph_attr)
{
	t_philo_attr	*ph;

	ph = (t_philo_attr *)ph_attr;
	if (ph->num % 2 == 0)
		xusleep(ph->phc->eat_t + (ph->phc->eat_t / 100LL));
	if (ph->pc->philo_count == 1)
		return (take_fork(ph));
	while (true)
	{
		if (!take_forks(ph))
			break ;
		if (!eating(ph))
			break ;
		if (!take_down_forks(ph))
			break ;
		if (!sleeping(ph))
			break ;
		if (!thinking(ph))
			break ;
	}
	return (EXIT_SUCCESS);
}

bool	is_anyone_dead(t_public_config *pc)
{
	if (pc->is_anyone_dead)
		return (true);
	return (false);
}

bool	destroy_mutex(t_sim_stat *s)
{
	size_t	i;

	i = 0;
	while (i < s->pub_config->philo_count)
	{
		if (pthread_mutex_destroy(&(s->ph_config->fork_mutex[i])) != 0)
			return (abort_philo_msg(FMUTEX_DESTROY_ERROR));
		i++;
	}
	if (pthread_mutex_destroy(&(s->pub_config->m_mutex)) != 0)
		return (abort_philo_msg(MMUTEX_DESTROY_ERROR));
	return (true);
}

bool	start_simulation(t_sim_stat *s)
{
	size_t			i;
	pthread_t		m_thread;
	t_public_config	*pc;

	pc = s->pub_config;
	i = 0;
	while (i < pc->philo_count)
	{
		s->ph_attr[i]->ate_t = gettime();
		if (pthread_create(&(s->ph_attr[i]->thread), \
			NULL, start_philo_act, s->ph_attr[i]) != 0)
			return (abort_philo_msg(CREATE_THREAD_ERROR));
		i++;
	}
	if (pthread_create(&m_thread, NULL, monitor_philo, s->m_attr) != 0)
		return (abort_philo_msg(CREATE_THREAD_ERROR));
	if (pthread_join(m_thread, NULL) != 0)
		return (abort_philo_msg(JOIN_THREAD_ERROR));
	i = 0;
	while (i < pc->philo_count)
		if (pthread_join(s->ph_attr[i++]->thread, NULL) != 0)
			return (abort_philo_msg(DETACH_THREAD_ERROR));
	if (!destroy_mutex(s))
		return (false);
	return (true);
}
