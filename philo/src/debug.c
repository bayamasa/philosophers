/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:48:56 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/22 14:24:21 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_all_fork_status(t_philo_attr *ph)
{
	size_t	i;

	i = 0;
	printf("a->fork_count = %zu \n", ph->phc->fork_count);
	printf("print_all_fork_status start\n");
	while (i < ph->phc->fork_count)
	{
		if (ph->phc->is_fork_taken[i] == false)
		{
			printf("is_fork_taken[%zu] = %s\n", i, "false");
		}
		else if (ph->phc->is_fork_taken[i] == true)
		{
			printf("is_fork_taken[%zu] = %s\n", i, "true");
		}
		else
		{
			printf("is_fork_taken[%zu] = %s\n", i, "undefined");
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

void	debug_all_fork_normal(t_philo_attr *ph)
{
	size_t	i;

	i = 0;
	while (i < ph->phc->fork_count)
	{
		if (ph->phc->is_fork_taken[i] == false)
		{
			printf("is_fork_taken[%zu] = %s\n", i, "false");
		}
		else if (ph->phc->is_fork_taken[i] == true)
		{
			printf("is_fork_taken[%zu] = %s\n", i, "true");
		}
		else
		{
			printf("is_fork_taken[%zu] = %s\n", i, "undefined");
		}
		i++;
	}
}

void	print_args(t_philo_attr *ph)
{
	printf("time to death : %zu\n", ph->pc->die_t);
	printf("time to sleep : %zu\n", ph->phc->sleep_t);
	printf("time to eat : %zu\n", ph->phc->eat_t);
}
