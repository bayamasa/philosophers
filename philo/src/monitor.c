/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:01:07 by mhirabay          #+#    #+#             */
/*   Updated: 2022/02/01 07:08:07 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	is_philo_dead(t_sim_stat *s, size_t philo_i)
{
	if (gettime() - s->p_attr[philo_i].ate_t > s->p_attr[philo_i].die_t)
		return (true);
	return (false);
}

void	*monitor_philo(void *attr)
{
	size_t		i;
	t_sim_stat	*s;

	s = (t_sim_stat *)attr;
	while (true)
	{
		i = 0;
		while (i < s->philo_count)
		{
			if (!lock(s->m_attr.mutex))
					return (NULL);
			if (is_philo_dead(s, i))
			{
				s->is_anyone_dead = true;
				print_act_died(s->p_attr[i].num, gettime());
				if (!unlock(s->m_attr.mutex))
					return (NULL);
				return (NULL);
			}
			if (!unlock(s->m_attr.mutex))
				return (NULL);
			// アクセスするときにmutexかけなきゃいけないかも
			if (s->eat_limit_flag)
			{
				if (!lock(s->m_attr.mutex))
					return (NULL);
				if (is_eat_limit_surpassed(s))
				{
					if (!unlock(s->m_attr.mutex))
						return (NULL);
					return (NULL);
				}
				if (!unlock(s->m_attr.mutex))
					return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}
