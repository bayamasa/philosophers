/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:44:56 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/22 09:52:43 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char const *argv[])
{
	t_sim_stat	*sim_stat;

	sim_stat = (t_sim_stat *)malloc(sizeof(t_sim_stat));
	if (!check_args(argc, argv))
		return (EXIT_FAILURE);
	if (!init(sim_stat, argv))
		return (EXIT_FAILURE);
	if (!start_simulation(sim_stat))
		return (EXIT_FAILURE);
	free_all(sim_stat);
	return (EXIT_SUCCESS);
}
