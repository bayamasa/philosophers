/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_attr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 09:09:23 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/26 10:42:11 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_all_attr(t_philo_attr *a)
{
	// create_fork
	a->fork_count = a->philo_count;
	a->is_fork_taken = (int *)malloc(sizeof(int) * a->fork_count);
	if (a->is_fork_taken == NULL)
		return (abort_philo_msg(MALLOC_ERROR));
	// 最初に全部0埋め
	memset(a->is_fork_taken, false, a->fork_count);
	return (true);
}