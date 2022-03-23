/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:01:07 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/23 00:05:32 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	is_philo_dead(t_monitor_attr *m, size_t philo_i)
{
	// printf("mpc->die_t = %zu\n", m->pc->die_t);
	if (gettime() - m->ph_attr[philo_i]->ate_t > m->pc->die_t)
		return (true);
	return (false);
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
			if (m->pc->eat_limit_surpassed)
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
