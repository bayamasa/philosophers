/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 09:32:11 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/21 20:57:08 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*start_philo_act(void *ph_attr)
{
	t_philo_attr	*ph;

	ph = (t_philo_attr *)ph_attr;
	while (true)
	{
		if (!take_forks(ph))
			break ;
		if (!eating(ph))
			break ;
		if (!sleeping(ph))
			break ;
		if (!thinking(ph))
			break ;
	}
	return (0);
}

bool	is_anyone_dead(t_public_config *pc)
{
	if (pc->is_anyone_dead)
		return (true);
	return (false);
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
		usleep(70);
		s->ph_attr[i]->ate_t = gettime();
		if (pthread_create(&(s->ph_attr[i]->thread), \
			NULL, start_philo_act, s->ph_attr[i]) != 0)
			return (abort_philo_msg_with_free(CREATE_THREAD_ERROR, s));
		i++;
	}
	if (pthread_create(&m_thread, NULL, monitor_philo, s->m_attr) != 0)
		return (abort_philo_msg_with_free(CREATE_THREAD_ERROR, s));
	if (pthread_join(m_thread, NULL) != 0)
		return (abort_philo_msg_with_free(JOIN_THREAD_ERROR, s));
	i = 0;
	while (i < pc->philo_count)
	{
		if (pthread_detach(s->ph_attr[i]->thread) != 0)
			return (abort_philo_msg_with_free(DETACH_THREAD_ERROR, s));
		i++;
	}
	i = 0;
	while (i < pc->philo_count)
	{
		if (pthread_mutex_destroy(&(s->ph_config->fork_mutex[i])) != 0)
			return (abort_philo_msg_with_free(JOIN_THREAD_ERROR, s));
		i++;
	}
	return (true);
}
