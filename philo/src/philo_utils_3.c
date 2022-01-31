/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:48:03 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/31 19:50:31 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	lock(pthread_mutex_t mutex)
{
	if (pthread_mutex_lock(&mutex) != 0)
	{
		printf("lock error; : %s\n", strerror(errno));
		return (false);
	}
	return (true);
}

int	unlock(pthread_mutex_t mutex)
{
	if (pthread_mutex_unlock(&mutex) != 0)
	{
		printf("unlock error; : %s\n", strerror(errno));
		return (false);
	}
	return (true);
}

int	is_forks_unused(t_sim_stat *t, size_t r, size_t l)
{
	if (t->is_fork_taken[r] == false && t->is_fork_taken[l] == false)
		return (true);
	return (false);
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
