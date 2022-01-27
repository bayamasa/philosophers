/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:12:24 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/27 16:33:16 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	take_fork(t_sim_stat *s, size_t philo_i)
{
	size_t	right_i;
	size_t	left_i;

	// printf("before take fork\n");
	// print_all_fork_status(a);
	// printf("p_no = %zu\n", p_no);
	// printf("a->fork_count = %zu\n", a->fork_count);
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
	// mutexいれるならここ。
	if (pthread_mutex_lock(&(s->mutex)) != 0)
	{
		printf("dame\n");
		return (false);
	}
	s->is_fork_taken[right_i] = true;
	s->is_fork_taken[left_i] = true;
	// printf("after take fork\n");
	// print_all_fork_status(a);
	print_act_take_fork(s->p_attr[philo_i].num, gettime());
	return (true);
}

int	take_down_fork(t_sim_stat *a, size_t philo_i)
{
	// mutex解除
	if (pthread_mutex_unlock(&(a->mutex)) != 0)
	{
		printf("dame\n");
		return (false);
	}
	(void)a;
	(void)philo_i;
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
