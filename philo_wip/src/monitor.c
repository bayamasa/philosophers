/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:01:07 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/22 00:07:06 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	is_philo_dead(t_monitor_attr *m, size_t philo_i)
{
	if (!lock(m->pc->m_mutex))
		return (false);
	if (gettime() - m->ph_attr[philo_i]->ate_t > m->pc->die_t)
		return (true);
	if (!unlock(m->pc->m_mutex))
		return (false);
	return (false);
}

void	*monitor_philo(void *attr)
{
	size_t			i;
	t_monitor_attr	*m;

	m = (t_monitor_attr *)attr;
	while (true)
	{
		i = 0;
		while (i < m->pc->philo_count)
		{
			if (is_philo_dead(m, i))
			{
				if (!lock(m->pc->m_mutex))
					return (false);
				m->pc->is_anyone_dead = true;
				print_act_died(m->ph_attr[i]->num, gettime());
				if (!unlock(m->pc->m_mutex))
					return (NULL);
				return (NULL);
			}
			if (!lock(m->pc->m_mutex))
				return (false);
			if (m->pc->eat_limit_surpassed)
			{
				if (!unlock(m->pc->m_mutex))
					return (NULL);
				return (NULL);
			}
			if (!unlock(m->pc->m_mutex))
				return (NULL);
			i++;
		}
	}
	return (NULL);
}
