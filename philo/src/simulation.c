/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 09:32:11 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/26 15:20:10 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	take_fork(t_philo_attr *a, size_t p_no)
{
	size_t	right_i;
	size_t	left_i;

	print_all_fork_status(a);
	if (p_no == 1)
	{
		right_i = p_no - 1;
		left_i = a->fork_count - 1;
	}
	else
	{
		right_i = p_no;
		left_i = p_no - 1;
	}
	// mutexいれるならここ。
	a->is_fork_taken[right_i] = true;
	a->is_fork_taken[left_i] = true;
	print_all_fork_status(a);
	return (true);
}

void	*start_philo_act(void *attr)
{
	t_philo_attr	*a;
	struct timeval	tv;
	static size_t	philo_num = 0;

	a = (t_philo_attr *)attr;
	// threadの番号管理のため、哲学者No.を定義
	philo_num++;
	debug_thread_start(philo_num);
	// forkを取る
	if (!take_fork(a, philo_num))
	{
		abort_philo_msg_with_free(CANNOT_TAKEN_FORK, a);
		// threadの中で以上を検知した場合どうやって対処するか、後で調べる。
		return (0);
	}
		
	// 食べる
	// 寝る
	// 考える
	gettimeofday(&tv, NULL);
	printf("[%ld%d]\n", tv.tv_sec, tv.tv_usec);
	return (0);
}


int	start_simulation(t_philo_attr *a)
{
	size_t			i;
	int				status;
	pthread_t		thread;

	i = 0;
	while (i < a->philo_count)
	{
		status = pthread_create(&thread, NULL, start_philo_act, a);
		if (status != 0)
			return (abort_philo_msg_with_free(CREATE_THREAD_ERROR, a));
		i++;
	}
	status = pthread_join(thread, NULL);
	if (status != 0) {
		// pthread_joinが失敗した場合は0以外の値を返す
		return (abort_philo_msg_with_free(CREATE_THREAD_ERROR, a));
	}
	return (true);
}
