/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:01:07 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/28 06:45:24 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	philo_is_died(t_sim_stat *s, size_t philo_i)
{
	if (gettime() - s->p_attr[philo_i].ate_t > s->p_attr[philo_i].die_t)
		return (true);
	return (false);
}


void	*monitor_philo(void *attr)
{
	size_t		i;
	t_sim_stat	*s;

	i = 0;
	s = (t_sim_stat *)attr;
	while (true)
	{
		while (i < s->philo_count)
		{
			// 現在時刻 - 最後に食べた時間(開始時間)が死ぬまでの時間を上回ったとき
			if (philo_is_died(s, i))
			{
				print_act_died(s->p_attr[i].num, gettime());
				return (0);
			}
			i++;
		}
	}
	return (0);
}
