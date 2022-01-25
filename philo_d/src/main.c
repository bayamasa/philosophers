/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:44:56 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/25 22:29:00 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void *thread_func(void *stat)
{
	t_status *s;
	s = (t_status *)stat;
	return (0);
}


int	main(int argc, char const *argv[])
{
	size_t		i;
	int			status;
	t_status	stat;
	pthread_t	thread;

	i = 0;
	if (!check_args(argc, argv, &stat))
		return (EXIT_FAILURE);
	while (i < stat.philo_num)
	{
		status = pthread_create(&thread, NULL, thread_func, (&stat));
	}
	
	return (0);
}

