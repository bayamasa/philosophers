/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 09:32:11 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/26 17:47:08 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*start_philo_act(void *attr)
{
	t_philo_attr	*a;
	size_t			philo_num;

	a = (t_philo_attr *)attr;
	// 食事したtimeを初期化。これで最初に食べたときの判定をする。
	a->ate_t = 0;
	printf("a->philo_num in func= %zu\n", a->philo_num);
	philo_num = a->philo_num;
	sleep(1);
	printf("philo_num = %zu\n", philo_num);
	debug_thread_start(philo_num);
	while (true)
	{
		take_fork(a, philo_num);
		eating(a, philo_num);
		sleeping(a, philo_num);
		thinking(philo_num);
		sleep(5);
	}
	return (0);
}

int	start_simulation(t_philo_attr *a)
{
	size_t			i;
	int				status;
	pthread_t		thread;

	i = 0;
	a->start_t = gettime();
	while (i < a->philo_count)
	{
		sleep(2);
		// こいつが更新される前に、L24に値を代入しないと行けない
		// ほかの方法あるんか？
		a->philo_num = i + 1;
		printf("a->philo_num = %zu\n", a->philo_num);
		status = pthread_create(&thread, NULL, start_philo_act, a);
		if (status != 0)
			return (abort_philo_msg_with_free(CREATE_THREAD_ERROR, a));
		i++;
	}
	i = 0;
	while (i < a->philo_count)
	{
		status = pthread_join(thread, NULL);
		if (status != 0)
			return (abort_philo_msg_with_free(JOIN_THREAD_ERROR, a));
		i++;
	}
	return (true);
}
