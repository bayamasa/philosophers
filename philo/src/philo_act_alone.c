/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act_alone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:13:44 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/23 12:14:09 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*take_fork(t_philo_attr *ph)
{
	print_act_take_fork(ph);
	xusleep(ph->pc->die_t * 2);
	return (NULL);
}
