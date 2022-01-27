/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 09:32:11 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/27 19:52:13 by mhirabay         ###   ########.fr       */
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
	usleep(50);
	while (true)
	{
		take_fork(a, thread_i);
		eating(a, thread_i);
		sleeping(a, thread_i);
		thinking(a, thread_i);
	}
	return (0);
}

void	*monitor_thread(void *attr)
{
	size_t		i;
	t_sim_stat	*s;

	i = 0;
	s = (t_sim_stat *)attr;
	while (true)
	{
		while (i < s->philo_count)
		{
			// 現在時刻 - 最後に食べた時間(開始時間)が死ぬまでの時間を上回ったとき
			if (gettime() - s->p_attr[i].ate_t > s->p_attr[i].die_t)
			{
				print_act_died(s->p_attr[i].num, gettime());
				return (0);
			}
			i++;
		}
	}
	return (0);
}

int	start_simulation(t_sim_stat *s)
{
	size_t			i;
	pthread_t		p_thread;
	pthread_t		m_thread;

	i = 0;
	while (i < s->philo_count)
	{
		usleep(200);
		// こいつが更新される前に、L24に値を代入しないと行けない
		// ほかの方法あるんか？
		s->thread_i = i;
		// simulation start timeをate_timeとして扱う。
		s->p_attr[i].ate_t = gettime();
		if (pthread_create(&p_thread, NULL, start_philo_act, s) != 0)
			return (abort_philo_msg_with_free(CREATE_THREAD_ERROR, s));
		i++;
	}
	if (pthread_create(&m_thread, NULL, monitor_thread, s) != 0)
		return (abort_philo_msg_with_free(CREATE_THREAD_ERROR, s));
	if (pthread_join(m_thread, NULL) != 0)
		return (abort_philo_msg_with_free(JOIN_THREAD_ERROR, s));
	return (true);
}
