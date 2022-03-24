/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:48:03 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/24 11:44:54 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	lock(pthread_mutex_t *mutex)
{
	if (pthread_mutex_lock(mutex) != 0)
	{
		return (abort_philo_msg(LOCK_ERROR));
	}
	return (true);
}

bool	unlock(pthread_mutex_t *mutex)
{
	if (pthread_mutex_unlock(mutex) != 0)
	{
		return (abort_philo_msg(UNLOCK_ERROR));
	}
	return (true);
}

void	*ft_memset(void *buf, int ch, size_t n)
{
	unsigned char	*dest;
	unsigned char	chr;
	size_t			i;

	i = 0;
	dest = (unsigned char *)buf;
	chr = (unsigned char)ch;
	while (i < n)
	{
		dest[i] = chr;
		i++;
	}
	return (dest);
}

bool	finish_thread(t_philo_attr *ph)
{
	size_t	right_i;
	size_t	left_i;

	get_forks_position(ph->phc->fork_count, ph->index, &right_i, &left_i);
	unlock(&(ph->phc->fork_mutex[right_i]));
	unlock(&(ph->phc->fork_mutex[left_i]));
	return (false);
}

bool	finish_thread_when_taken_one_fork(t_philo_attr *ph)
{
	size_t	right_i;
	size_t	left_i;

	get_forks_position(ph->phc->fork_count, ph->index, &right_i, &left_i);
	unlock(&(ph->phc->fork_mutex[right_i]));
	return (false);
}
