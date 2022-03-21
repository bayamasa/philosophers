/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:12:24 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/21 20:25:10 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	take_forks(t_philo_attr *ph)
{
	size_t	right_i;
	size_t	left_i;

	get_forks_position(ph->phc->fork_count, ph->index, &right_i, &left_i);
	if (!lock(ph->phc->fork_mutex[right_i]))
		return (false);
	while (true)
	{
		if (ph->phc->is_fork_taken[right_i] == false)
		{
			ph->phc->is_fork_taken[right_i] = true;
			break ;
		}
	}
	if (!lock(ph->phc->fork_mutex[left_i]))
		return (false);
	while (true)
	{
		if (ph->phc->is_fork_taken[left_i] == false)
		{
			ph->phc->is_fork_taken[left_i] = true;
			break ;
		}
	}
	print_act_take_fork(ph, gettime());
	return (true);
}

bool	eating(t_philo_attr *ph)
{
	print_act_eating(ph, gettime());
	usleep(ph->phc->eat_t);
	if (!lock(ph->pc->m_mutex))
		return (false);
	ph->pc->eat_count++;
	if (is_eat_limit_surpassed(ph->pc))
		return (false);
	if (!unlock(ph->pc->m_mutex))
		return (false);
	if (!take_down_forks(ph))
		return (false);
	return (true);
}

bool	take_down_forks(t_philo_attr *ph)
{
	size_t	right_i;
	size_t	left_i;

	get_forks_position(ph->phc->fork_count, ph->index, &right_i, &left_i);
	while (true)
	{
		if (ph->phc->is_fork_taken[right_i] == true)
		{
			ph->phc->is_fork_taken[right_i] = false;
			break ;
		}
	}
	if (!unlock(ph->phc->fork_mutex[right_i]))
		return (false);
	while (true)
	{	
		if (ph->phc->is_fork_taken[left_i] == true)
		{
			ph->phc->is_fork_taken[left_i] = false;
			break ;
		}
	}
	if (!unlock(ph->phc->fork_mutex[left_i]))
		return (false);
	return (true);
}

bool	sleeping(t_philo_attr *ph)
{
	print_act_sleeping(ph, gettime());
	usleep(ph->phc->sleep_t);
	return (true);
}

bool	thinking(t_philo_attr *ph)
{
	print_act_thinking(ph, gettime());
	return (true);
}
