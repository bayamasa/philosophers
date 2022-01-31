/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:48:56 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/31 19:50:41 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_all_fork_status(t_sim_stat *a)
{
	size_t	i;

	i = 0;
	printf("a->fork_count = %zu \n", a->fork_count);
	printf("print_all_fork_status start\n");
	while (i < a->fork_count)
	{
		if (a->is_fork_taken[i] == false)
		{
			printf("is_fork_taken[%zu] = %s\n", i,"false");
		}
		else if (a->is_fork_taken[i] == true)
		{
			printf("is_fork_taken[%zu] = %s\n", i,"true");
		}
		else
		{
			printf("is_fork_taken[%zu] = %s\n", i,"undefined");
		}
		i++;
	}
	printf("print_all_fork_status end\n");
}

void	debug_thread_start(size_t count)
{
	printf("thread num = %zu start\n", count);
}

void	print_act_takedown_fork(size_t philo, size_t time)
{
	printf("%zu %zu has taken down a fork debug\n", time, philo);
}

void	debug_all_fork_normal(t_sim_stat *s)
{
	size_t	i;

	i = 0;
	while (i < s->fork_count)
	{
		if (s->is_fork_taken[i] == false)
		{
			printf("is_fork_taken[%zu] = %s\n", i,"false");
		}
		else if (s->is_fork_taken[i] == true)
		{
			printf("is_fork_taken[%zu] = %s\n", i,"true");
		}
		else
		{
			printf("is_fork_taken[%zu] = %s\n", i,"undefined");
		}
		i++;
	}
}
