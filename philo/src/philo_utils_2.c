/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:40:04 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/31 20:14:42 by mhirabay         ###   ########.fr       */
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
	time = tv.tv_sec * USEC_DIGITS + tv.tv_usec;
	return (time);
}

void	get_forks_position(size_t fork_count, size_t p_i, size_t *r, size_t *l)
{
	*r = p_i;
	if (p_i == 0)
		*l = fork_count - 1;
	else
		*l = p_i - 1;
	printf("p_i = %zu\n", p_i);
	printf("*r = %zu\n", *r);
	printf("*l = %zu\n", *l);
}

bool	is_eat_limit_surpassed(t_sim_stat *s)
{
	if (s->eat_count >= s->eat_limit)
		return (true);
	return (false);
}
