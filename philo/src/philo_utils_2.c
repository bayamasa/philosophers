/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:40:04 by mhirabay          #+#    #+#             */
/*   Updated: 2022/04/24 20:38:02 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	gettime(void)
{
	size_t			time;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}

void	get_forks_position(size_t fork_count, size_t p_i, size_t *r, size_t *l)
{
	*r = p_i;
	if (p_i == 0)
		*l = fork_count - 1;
	else
		*l = p_i - 1;
}

bool	is_eat_limit_surpassed(t_philo_attr *ph)
{
	if (ph->pc->eat_limit_exist == false)
		return (false);
	if (!lock(&ph->pc->m_mutex))
		return (false);
	ph->times_eaten += 1;
	if (ph->times_eaten >= ph->pc->eat_limit)
	{
		ph->is_eaten = true;
		if (!unlock(&ph->pc->m_mutex))
			return (false);
		return (true);
	}
	if (!unlock(&ph->pc->m_mutex))
		return (false);
	return (false);
}

int	ft_isspace(char a)
{
	if (a == '\t' || a == '\n' || a == '\v'
		|| a == ' ' || a == '\r' || a == '\f' )
		return (1);
	return (0);
}
