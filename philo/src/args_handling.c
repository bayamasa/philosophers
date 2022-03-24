/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:40:36 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/24 11:49:35 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	validate_philo_count(const char *str, int *status)
{
	long	val;

	val = ft_atoi_error(str, status);
	if (val < 1 || val > PHILO_COUNT_MAX)
		*status = false;
}

void	validate_time(const char *str, int *status)
{
	long	val;

	val = ft_atoi_error(str, status);
	if (val < 1 || val > INT_MAX)
		*status = false;
}

void	validate_eat_limit(const char *str, int *status)
{
	long	val;

	val = ft_atoi_error(str, status);
	if (val < 1 || val > INT_MAX)
		*status = false;
}

bool	check_args(int argc, const char *argv[])
{
	int	status;

	if (argc != 5 && argc != 6)
		return (abort_philo_msg(ARGS_ERROR));
	status = true;
	validate_philo_count(argv[NUMBER_OF_PHILOSOPHERS], &status);
	validate_time(argv[TIME_TO_DIE], &status);
	validate_time(argv[TIME_TO_EAT], &status);
	validate_time(argv[TIME_TO_SLEEP], &status);
	if (argc == 6)
		ft_atoi_error(argv[TIMES_PHILO_MUST_EAT], &status);
	if (status == false)
		return (abort_philo_msg(ARGS_ERROR));
	return (true);
}
