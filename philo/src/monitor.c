/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:01:07 by mhirabay          #+#    #+#             */
/*   Updated: 2022/04/24 20:21:30 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	is_philo_dead(t_monitor_attr *m, size_t philo_i)
{
	if (gettime() - m->ph_attr[philo_i]->ate_t > m->pc->die_t)
		return (true);
	return (false);
}

bool	is_all_philo_eaten_limit(t_monitor_attr *m)
{
	size_t	i;

	i = 0;
	while (i < m->pc->philo_count)
	{
		if (!m->ph_attr[i]->is_eaten)
			return (false);
		i++;
	}
	return (true);
}

void	*act_philo_died(t_monitor_attr *m, size_t i)
{
	m->pc->is_anyone_dead = true;
	print_act_died(m->ph_attr[i]->num);
	unlock(&(m->pc->m_mutex));
	return (NULL);
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
			if (!lock(&(m->pc->m_mutex)))
				return (NULL);
			if (is_philo_dead(m, i))
				return (act_philo_died(m, i));
			if (is_all_philo_eaten_limit(m))
			{
				unlock(&(m->pc->m_mutex));
				return (NULL);
			}
			if (!unlock(&(m->pc->m_mutex)))
				return (NULL);
			i++;
		}
	}
	return (NULL);
}
