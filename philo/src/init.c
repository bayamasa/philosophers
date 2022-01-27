/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 09:09:23 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/27 17:00:38 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_philo_attr(t_sim_stat *s, const char *argv[])
{
	size_t	i;
	int		status;

	i = 0;
	status = true;
	s->p_attr = (t_philo_attr *)malloc(sizeof(t_philo_attr) * s->philo_count);
	if (s->p_attr == NULL)
		return (false);
	while (i < s->philo_count)
	{
		s->p_attr->num = i + 1;
		s->p_attr->die_t = ft_atoi_error(argv[TIME_TO_DIE], &status);
		s->p_attr->eat_t = ft_atoi_error(argv[TIME_TO_EAT], &status);
		s->p_attr->sleep_t = ft_atoi_error(argv[TIME_TO_SLEEP], &status);
		// TODO: 下2つは必要かどうかわからんけど一応
		s->p_attr->start_t = 0;
		s->p_attr->ate_t = 0;
		i++;
	}
	return (true);
}

int	init(t_sim_stat *s, const char *argv[])
{
	int		status;

	if (pthread_mutex_init(&(s->mutex), NULL) == -1)
		return (abort_philo_msg(MUTEX_INIT_ERROR));
	//TODO: statusが必要ないatoi or strtollを作る
	status = true;
	s->philo_count = ft_atoi_error(argv[NUMBER_OF_PHILOSOPHERS], &status);
	if (!init_philo_attr(s, argv))
		return (abort_philo_msg(MALLOC_ERROR));
	s->fork_count = s->philo_count;
	if (argv[TIMES_PHILO_MUST_EAT] != NULL)
		s->meal_limits = ft_atoi_error(argv[TIMES_PHILO_MUST_EAT], &status);
	s->is_fork_taken = (int *)malloc(sizeof(int) * s->fork_count);
	if (s->is_fork_taken == NULL)
		return (abort_philo_msg_with_free(MALLOC_ERROR, s));
	// 最初に全部0埋め
	memset(s->is_fork_taken, false, s->fork_count);
	return (true);
}
