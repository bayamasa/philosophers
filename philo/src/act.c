/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:12:24 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/28 06:39:37 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	take_fork(t_sim_stat *s, size_t philo_i)
{
	size_t	right_i;
	size_t	left_i;

	if (philo_i == 0)
	{
		right_i = philo_i;
		left_i = s->fork_count - 1;
	}
	else
	{
		right_i = philo_i + 1;
		left_i = philo_i;
	}
	if (pthread_mutex_lock(&(s->mutex)) != 0)
	{
		printf("strerror(errno); : %s\n", strerror(errno));
		printf("dame lock\n");
		return (false);
	}
	s->is_fork_taken[right_i] = true;
	s->is_fork_taken[left_i] = true;
	print_act_take_fork(s->p_attr[philo_i].num, gettime());
	return (true);
}

int	take_down_fork(t_sim_stat *s, size_t philo_i)
{
	size_t	right_i;
	size_t	left_i;

	if (philo_i == 0)
	{
		right_i = philo_i;
		left_i = s->fork_count - 1;
	}
	else
	{
		right_i = philo_i + 1;
		left_i = philo_i;
	}
	s->is_fork_taken[right_i] = false;
	s->is_fork_taken[left_i] = false;
	// mutex解除
	if (pthread_mutex_unlock(&(s->mutex)) != 0)
	{
		printf("strerror(errno); : %s\n", strerror(errno));
		printf("dame unlock\n");
		return (false);
	}
	print_act_takedown_fork(s->p_attr[philo_i].num, gettime());
	return (0);
}

void	eating(t_sim_stat *s, size_t philo_i)
{
	// updaate ate_time;
	s->p_attr[philo_i].ate_t = gettime();
	print_act_eating(s->p_attr[philo_i].num, s->p_attr[philo_i].ate_t);
	usleep(s->p_attr[philo_i].eat_t);
	take_down_fork(s, philo_i);
}

void	sleeping(t_sim_stat *s, size_t philo_i)
{
	print_act_sleeping(s->p_attr[philo_i].num, gettime());
	usleep(s->p_attr[philo_i].sleep_t);
}

void	thinking(t_sim_stat *s, size_t philo_i)
{
	print_act_thinking(s->p_attr[philo_i].num, gettime());
}
