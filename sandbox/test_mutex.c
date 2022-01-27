/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 10:04:52 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/27 18:17:48 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo/includes/philo.h"
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;


void	*test_mutex(void *status)
{
	int	*s;

	printf("kita 1\n");
	s = (int *)status;
	// usleep(100);
	if (pthread_mutex_lock(&m) != 0)
	{
		printf("dame\n");
		exit(EXIT_FAILURE);
	}
	printf("test 1 lock start\n");
	printf("*s in lock = %d\n", *s);
	*s = 1000000;
	sleep(1);
	printf("*s in lock = after %d\n", *s);
	if (pthread_mutex_unlock(&m) != 0)
	{
		printf("dame\n");
		exit(EXIT_FAILURE);
	}
	printf("test 1 lock end\n");
	return 0;
}

void	*test_mutex_2(void *status)
{
	int	*s;

	printf("kita 2\n");
	s = (int *)status;
	usleep(100);
	if (pthread_mutex_lock(&m) != 0)
	{
		printf("dame\n");
		exit(EXIT_FAILURE);
	}
	printf("test 2 lock start\n");
	*s = 1;
	if (pthread_mutex_unlock(&m) != 0)
	{
		printf("dame\n");
		exit(EXIT_FAILURE);
	}
	printf("test 2 lock end\n");

	printf("s in test_2 = %d\n", *s);
	return 0;
}

int	main(void)
{
	pthread_t	thread;
	int			status;

	status = 100;
	printf("status = %d\n", status);
	if (pthread_create(&thread, NULL, test_mutex, &status) != 0)
	{
		printf("dame\n");
	}

	usleep(500);
	if (pthread_create(&thread, NULL, test_mutex_2, &status) != 0)
	{
		printf("dame\n");
	}
	//
	sleep(5);
	printf("status = %d\n", status);
	return (0);
}
