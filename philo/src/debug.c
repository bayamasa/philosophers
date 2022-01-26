/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:48:56 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/26 14:21:33 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_all_fork_status(t_philo_attr *a)
{
	size_t	i;

	i = 0;
	printf("a->fork_count = %zu\n", a->fork_count);
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
