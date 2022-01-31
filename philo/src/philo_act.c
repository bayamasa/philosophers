/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:12:24 by mhirabay          #+#    #+#             */
/*   Updated: 2022/02/01 07:26:30 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	take_forks(t_sim_stat *s, size_t philo_i)
{
	size_t	right_i;
	size_t	left_i;

	get_forks_position(s->fork_count, philo_i, &right_i, &left_i);
	if (!lock(s->fork_mutex[right_i]))
		return (false);
	while (true)
	{
		if (s->is_fork_taken[right_i] == false)
		{
			s->is_fork_taken[right_i] = true;
			break ;
		}
	}
	if (!lock(s->fork_mutex[left_i]))
		return (false);
	while (true)
	{
		if (s->is_fork_taken[left_i] == false)
		{
			s->is_fork_taken[left_i] = true;
			break ;
		}
	}
	print_act_take_fork(s, s->p_attr[philo_i].num, gettime());
	return (true);
}

bool	eating(t_sim_stat *s, size_t philo_i)
{
	if (!lock(s->m_attr.mutex))
		return (false);
	print_act_eating(s, s->p_attr[philo_i].num, gettime(), philo_i);
	usleep(s->p_attr[philo_i].eat_t);
	s->eat_count++;
	if (is_eat_limit_surpassed(s))
		return (false);
	if (!unlock(s->m_attr.mutex))
		return (false);
	if (!take_down_forks(s, philo_i))
		return (false);
	return (true);
}

bool	take_down_forks(t_sim_stat *s, size_t philo_i)
{
	size_t	right_i;
	size_t	left_i;

	get_forks_position(s->fork_count, philo_i, &right_i, &left_i);
	while (true)
	{
		if (s->is_fork_taken[right_i] == true)
		{
			s->is_fork_taken[right_i] = false;
			break ;
		}
	}
	if (!unlock(s->fork_mutex[right_i]))
		return (false);
	while (true)
	{	
		if (s->is_fork_taken[left_i] == true)
		{
			s->is_fork_taken[left_i] = false;
			break ;
		}
	}
	if (!unlock(s->fork_mutex[left_i]))
		return (false);
	return (true);
}

bool	sleeping(t_sim_stat *s, size_t philo_i)
{
	print_act_sleeping(s, s->p_attr[philo_i].num, gettime());
	usleep(s->p_attr[philo_i].sleep_t);
	return (true);
}

bool	thinking(t_sim_stat *s, size_t philo_i)
{
	print_act_thinking(s, s->p_attr[philo_i].num, gettime());
	return (true);
}
