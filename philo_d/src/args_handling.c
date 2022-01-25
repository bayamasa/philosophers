/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:40:36 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/25 16:29:50 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"



int	check_args(int argc, char *argv[], t_status *s)
{
	int	i;
	int	size;
	int	status;

	if (argc == 4 || argc == 5)
		return (false);
	i = 0;
	size = argc - 1;
	status = true;
	s->philo_num = ft_atoi_error(argv[1], &status);
	s->die_t = ft_atoi_error(argv[2], &status);
	s->eat_t = ft_atoi_error(argv[3], &status);
	s->sleep_t = ft_atoi_error(argv[4], &status);
	if (status == false)
		return (abort_philo_msg(ARGS_ERROR));
	return (true);
}
