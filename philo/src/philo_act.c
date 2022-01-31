/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:12:24 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/31 15:40:51 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	take_forks(t_sim_stat *s, size_t philo_i)
{
	size_t	right_i;
	size_t	left_i;

	get_forks_position(s->fork_count, philo_i, &right_i, &left_i);
	while (true)
	{
		if (is_forks_unused(s, right_i, left_i))
		{
			if (!lock(s->mutex))
				return (false);
			s->is_fork_taken[right_i] = true;
			s->is_fork_taken[left_i] = true;
			if (!unlock(s->mutex))
				return (false);
			break ;
		}
	}
	if (!print_act_take_fork(s, s->p_attr[philo_i].num, gettime()))
		return (false);
	return (true);
}

int	eating(t_sim_stat *s, size_t philo_i)
{

	if (!print_act_take_fork(s, s->p_attr[philo_i].num, gettime()))
		return (false);
	s->p_attr[philo_i].ate_t = gettime();
	print_act_eating(s, s->p_attr[philo_i].num, s->p_attr[philo_i].ate_t);
	usleep(s->p_attr[philo_i].eat_t);
	if (!lock(s->m_attr.mutex))
		return (false);
	s->eat_count++;
	if (!unlock(s->m_attr.mutex))
		return (false);
	printf("eat_count = %zu\n", s->eat_count);
	return (true);
}

int	take_down_forks(t_sim_stat *s, size_t philo_i)
{
	size_t	right_i;
	size_t	left_i;

	get_forks_position(s->fork_count, philo_i, &right_i, &left_i);
	if (!lock(s->mutex))
		return (false);
	s->is_fork_taken[right_i] = false;
	s->is_fork_taken[left_i] = false;
	if (!unlock(s->mutex))
		return (false);
	return (0);
}



int	sleeping(t_sim_stat *s, size_t philo_i)
{
	print_act_sleeping(s, s->p_attr[philo_i].num, gettime());
	usleep(s->p_attr[philo_i].sleep_t);
	return (true);
}

int	thinking(t_sim_stat *s, size_t philo_i)
{
	print_act_thinking(s, s->p_attr[philo_i].num, gettime());
	return (true);
}
