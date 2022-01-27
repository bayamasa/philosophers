/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:12:24 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/27 11:54:29 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	take_fork(t_sim_stat *a, size_t p_no)
{
	size_t	right_i;
	size_t	left_i;

	// printf("before take fork\n");
	// print_all_fork_status(a);
	// printf("p_no = %zu\n", p_no);
	// printf("a->fork_count = %zu\n", a->fork_count);
	if (p_no == 1)
	{
		right_i = p_no - 1;
		left_i = a->fork_count - 1;
	}
	else
	{
		right_i = p_no;
		left_i = p_no - 1;
	}
	// mutexいれるならここ。
	if (pthread_mutex_lock(&(a->mutex)) != 0)
	{
		printf("dame\n");
		return (false);
	}
	a->is_fork_taken[right_i] = true;
	a->is_fork_taken[left_i] = true;
	// printf("after take fork\n");
	// print_all_fork_status(a);
	print_act_take_fork(p_no, gettime());
	return (true);
}

int	take_down_fork(t_sim_stat *a, size_t p_no)
{
	// mutex解除
	if (pthread_mutex_unlock(&(a->mutex)) != 0)
	{
		printf("dame\n");
		return (false);
	}
	(void)a;
	(void)p_no;
	return (0);
}

void	eating(t_sim_stat *a, size_t p_no)
{
	// updaate ate_time;
	a->ate_t = gettime();
	print_act_eating(p_no, a->ate_t);
	usleep(a->eat_t);
	take_down_fork(a, p_no);
}

void	sleeping(t_sim_stat *a, size_t p_no)
{
	print_act_sleeping(p_no, gettime());
	usleep(a->sleep_t);
}

void	thinking(size_t p_no)
{
	print_act_thinking(p_no, gettime());
}
