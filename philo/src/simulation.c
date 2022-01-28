/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 09:32:11 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/28 10:25:12 by mhirabay         ###   ########.fr       */
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
	// usleep(50);
	while (true)
	{
		take_forks(a, thread_i);
		eating(a, thread_i);
		sleeping(a, thread_i);
		thinking(a, thread_i);
	}
	return (0);
}

int	is_anyone_dead(t_sim_stat *s)
{
	
	if (s->is_anyone_dead)
		return (true);
	return (false);
}

int	start_simulation(t_sim_stat *s)
{
	size_t			i;
	pthread_t		p_thread;
	pthread_t		m_thread;

	i = 0;
	while (i < s->philo_count)
	{
		usleep(20);
		// こいつが更新される前に、L24に値を代入しないと行けない
		// ほかの方法あるんか？
		s->thread_i = i;
		// simulation start timeをate_timeとして扱う。
		s->p_attr[i].ate_t = gettime();
		if (pthread_create(&p_thread, NULL, start_philo_act, s) != 0)
			return (abort_philo_msg_with_free(CREATE_THREAD_ERROR, s));
		i++;
	}
	if (pthread_create(&m_thread, NULL, monitor_philo, s) != 0)
		return (abort_philo_msg_with_free(CREATE_THREAD_ERROR, s));
	if (pthread_join(m_thread, NULL) != 0)
		return (abort_philo_msg_with_free(JOIN_THREAD_ERROR, s));
	return (true);
}
