/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:10:18 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/28 06:54:50 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_act_take_fork(size_t philo, size_t time)
{
	printf("%zu %zu has taken a fork\n", time, philo);
}

void	print_act_eating(size_t philo, size_t time)
{
	printf("%zu %zu is eating\n", time, philo);
}

void	print_act_sleeping(size_t philo, size_t time)
{
	printf("%zu %zu is sleeping\n", time, philo);
}

void	print_act_thinking(size_t philo, size_t time)
{
	printf("%zu %zu is thinking\n", time, philo);
}

void	print_act_died(size_t philo, size_t time)
{
	printf("%zu %zu died\n", time, philo);
}
