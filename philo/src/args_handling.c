/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:40:36 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/27 15:57:58 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// 各バリデーションが同じ条件になったからまとめてもいいかも
// msgを個別に定義するために、第3引数にmsgをポインタでもってもいいかも。
void	validate_philo_count(const char *str, int *status)
{
	size_t	val;

	val = ft_atoi_error(str, status);
	// valは1以上である。
	if (val <= 0)
		*status = false;
	return (val);
}

void	validate_time(const char *str, int *status)
{
	int	val;

	val = ft_atoi_error(str, status);
	// timeは1以上とする
	if (val <= 0)
		*status = false;
	return (val);
}

void	validate_eat_limit(const char *str, int *status)
{
	int	val;

	val = ft_atoi_error(str, status);
	// eat_limitは1以上である(予定)
	if (val <= 0)
		*status = false;
	return (val);
}

int	check_args(int argc, const char *argv[], t_sim_stat *a)
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
		ft_atoi_error(argv[NUMBER_OF_TIMES_PHILO_MUST_EAT], &status);
	if (status == false)
		return (abort_philo_msg(ARGS_ERROR));
	return (true);
}
