/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:44:56 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/26 07:16:49 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void *thread_func(void *attr)
{
	t_philo_attr *a;

	a = (t_philo_attr *)attr;
	return (0);
}


int	main(int argc, char const *argv[])
{
	size_t			i;
	int				status;
	t_philo_attr	attr;
	pthread_t		thread;

	i = 0;
	if (!check_args(argc, argv, &attr))
		return (EXIT_FAILURE);
	init_all_status(&attr);
	while (i < attr.philo_num)
	{
		status = pthread_create(&thread, NULL, thread_func, (&attr));
	}
	
	return (0);
}

