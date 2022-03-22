/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:12:24 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/22 21:35:46 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	finish_thread(t_philo_attr *ph)
{
	size_t	right_i;
	size_t	left_i;

	get_forks_position(ph->phc->fork_count, ph->index, &right_i, &left_i);
	unlock(&(ph->phc->fork_mutex[right_i]));
	unlock(&(ph->phc->fork_mutex[left_i]));
	return (false);
}

bool	finish_thread_when_taken_one_fork(t_philo_attr *ph)
{
	size_t	right_i;
	size_t	left_i;

	get_forks_position(ph->phc->fork_count, ph->index, &right_i, &left_i);
	unlock(&(ph->phc->fork_mutex[right_i]));
	return (false);
}

bool	take_forks(t_philo_attr *ph)
{
	size_t	right_i;
	size_t	left_i;

	get_forks_position(ph->phc->fork_count, ph->index, &right_i, &left_i);
	if (!lock(&(ph->phc->fork_mutex[right_i])))
		return (false);
	ph->phc->is_fork_taken[right_i] = true;
	if (!print_act_take_fork(ph))
		return (finish_thread_when_taken_one_fork(ph));
	if (!lock(&(ph->phc->fork_mutex[left_i])))
		return (false);
	ph->phc->is_fork_taken[left_i] = true;
	if (!print_act_take_fork(ph))
		return (finish_thread(ph));
	return (true);
}

bool	eating(t_philo_attr *ph)
{
	if (!print_act_eating(ph))
		return (finish_thread(ph));
	xusleep(ph->phc->eat_t);
	if (!take_down_forks(ph))
		return (false);
	return (true);
}

bool	take_down_forks(t_philo_attr *ph)
{
	size_t	right_i;
	size_t	left_i;

	get_forks_position(ph->phc->fork_count, ph->index, &right_i, &left_i);
	if (is_eat_limit_surpassed(ph->pc))
	{
		return (finish_thread(ph));
	}
	if (ph->phc->is_fork_taken[right_i] == true)
		ph->phc->is_fork_taken[right_i] = false;
	if (!unlock(&(ph->phc->fork_mutex[right_i])))
		return (false);
	if (ph->phc->is_fork_taken[left_i] == true)
		ph->phc->is_fork_taken[left_i] = false;
	if (!unlock(&(ph->phc->fork_mutex[left_i])))
		return (false);
	return (true);
}

bool	sleeping(t_philo_attr *ph)
{
	print_act_sleeping(ph);
	xusleep(ph->phc->sleep_t);
	return (true);
}

bool	thinking(t_philo_attr *ph)
{
	print_act_thinking(ph);
	return (true);
}
