/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo_act.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:10:18 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/21 20:22:25 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	print_act_take_fork(t_philo_attr *ph, size_t time)
{
	if (!lock(ph->pc->m_mutex))
		return (false);
	if (!is_anyone_dead(ph->pc))
		printf("%zu %zu has taken a fork\n", time, ph->num);
	if (!unlock(ph->pc->m_mutex))
		return (false);
	return (true);
}

bool	print_act_eating(t_philo_attr *ph, size_t time)
{
	if (!lock(ph->pc->m_mutex))
		return (false);
	ph->ate_t = time;
	if (!is_anyone_dead(ph->pc))
		printf("%zu %zu is eating\n", time, ph->num);
	if (!unlock(ph->pc->m_mutex))
		return (false);
	return (true);
}

bool	print_act_sleeping(t_philo_attr *ph, size_t time)
{
	if (!lock(ph->pc->m_mutex))
		return (false);
	if (!is_anyone_dead(ph->pc))
		printf("%zu %zu is sleeping\n", time, ph->num);
	if (!unlock(ph->pc->m_mutex))
		return (false);
	return (true);
}

bool	print_act_thinking(t_philo_attr *ph, size_t time)
{
	if (!lock(ph->pc->m_mutex))
		return (false);
	if (!is_anyone_dead(ph->pc))
		printf("%zu %zu is thinking\n", time, ph->num);
	if (!unlock(ph->pc->m_mutex))
		return (false);
	return (true);
}

bool	print_act_died(size_t philo, size_t time)
{
	printf("%zu %zu died\n", time, philo);
	return (true);
}
