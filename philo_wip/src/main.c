/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:44:56 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/28 17:04:20 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char const *argv[])
{
	t_sim_stat	stat;

	if (!check_args(argc, argv))
		return (EXIT_FAILURE);
	if (!init(&stat, argv))
		return (EXIT_FAILURE);
	if (!start_simulation(&stat))
		return (EXIT_FAILURE);
	free_all(&stat);
	return (EXIT_SUCCESS);
}
