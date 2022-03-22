/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 09:09:23 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/22 14:21:11 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	init(t_sim_stat *s, const char *argv[])
{
	if (!init_all_config(s, argv))
		return (abort_philo_msg(MALLOC_ERROR));
	if (!init_philo_attr(s, argv))
		return (abort_philo_msg(MALLOC_ERROR));
	if (!init_monitor_attr(s))
		return (abort_philo_msg(MALLOC_ERROR));
	return (true);
}
