/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:44:56 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/24 11:27:51 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char const *argv[])
{
	t_sim_stat	sim_stat;

	if (!check_args(argc, argv))
		return (EXIT_FAILURE);
	if (!init(&sim_stat, argv))
		return (EXIT_FAILURE);
	if (!start_simulation(&sim_stat))
		return (EXIT_FAILURE);
	free_all(&sim_stat);
	return (EXIT_SUCCESS);
}

// __attribute__((destructor))
// static void destructor(){
// 	system("leaks -q philo");
// }
