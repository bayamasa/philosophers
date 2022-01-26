/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:44:56 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/26 10:42:23 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char const *argv[])
{
	t_philo_attr	attr;

	if (!check_args(argc, argv, &attr))
		return (EXIT_FAILURE);
	if (!init_all_attr(&attr))
		return (EXIT_FAILURE);
	if (!start_simulation(&attr))
		return (EXIT_FAILURE);
	return (0);
}
