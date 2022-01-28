/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:10:18 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/28 16:10:41 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	print_act_take_fork(t_sim_stat *s, size_t philo, size_t time)
{
	if (!lock(s->mutex))
		return (false);
	if (!is_anyone_dead(s))
		printf("%zu %zu has taken a fork\n", time, philo);
	if (!unlock(s->mutex))
		return (false);
	return (true);
}

int	print_act_eating(t_sim_stat *s, size_t philo, size_t time)
{
	if (!lock(s->mutex))
		return (false);
	if (!is_anyone_dead(s))
		printf("%zu %zu is eating\n", time, philo);
	if (!unlock(s->mutex))
		return (false);
	return (true);
}

int	print_act_sleeping(t_sim_stat *s, size_t philo, size_t time)
{
	if (!lock(s->mutex))
		return (false);
	if (!is_anyone_dead(s))
		printf("%zu %zu is sleeping\n", time, philo);
	if (!unlock(s->mutex))
		return (false);
	return (true);
}

int	print_act_thinking(t_sim_stat *s, size_t philo, size_t time)
{
	if (!lock(s->mutex))
		return (false);
	if (!is_anyone_dead(s))
		printf("%zu %zu is thinking\n", time, philo);
	if (!unlock(s->mutex))
		return (false);
	return (true);
}

int	print_act_died(size_t philo, size_t time)
{
	printf("%zu %zu died\n", time, philo);
	return (true);
}
