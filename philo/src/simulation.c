/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 09:32:11 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/27 17:03:40 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*start_philo_act(void *attr)
{
	t_sim_stat	*a;
	size_t		thread_i;

	a = (t_sim_stat *)attr;
	// ここが次スレッド作成時に上書きされないようにする。
	thread_i = a->thread_i;
	sleep(1);
	printf("thread_i = %zu\n", thread_i);
	debug_thread_start(thread_i);
	while (true)
	{
		take_fork(a, thread_i);
		eating(a, thread_i);
		sleeping(a, thread_i);
		thinking(a, thread_i);
		sleep(5);
	}
	return (0);
}

void	*monitor_thread(void *attr)
{
	size_t	i;

	i = 0;
	t_sim_stat	*a;
	a = (t_sim_stat *)attr;
	while (i < a->philo_count)
	{
		a->p_attr[i].ate_t - 
	}
	
	return (0);
}

int	start_simulation(t_sim_stat *s)
{
	size_t			i;
	pthread_t		thread;

	i = 0;
	while (i < s->philo_count)
	{
		sleep(2);
		// こいつが更新される前に、L24に値を代入しないと行けない
		// ほかの方法あるんか？
		s->thread_i = i;
		s->p_attr[i].num = i + 1;
		if (pthread_create(&thread, NULL, start_philo_act, s) != 0)
			return (abort_philo_msg_with_free(CREATE_THREAD_ERROR, s));
		i++;
	}
	if (pthread_create(&thread, NULL, monitor_thread, s) != 0)
		return (abort_philo_msg_with_free(CREATE_THREAD_ERROR, s));
	i = 0;
	while (i < s->philo_count)
	{
		if (pthread_join(thread, NULL) != 0)
			return (abort_philo_msg_with_free(JOIN_THREAD_ERROR, s));
		i++;
	}
	return (true);
}
