/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:40:36 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/27 11:54:29 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// 各バリデーションが同じ条件になったからまとめてもいいかも
// msgを個別に定義するために、第3引数にmsgをポインタでもってもいいかも。
size_t	validate_philo_num(const char *str, int *status)
{
	size_t	val;

	val = ft_atoi_error(str, status);
	// valは1以上である。
	if (val <= 0)
		*status = false;
	return (val);
}

size_t	validate_time(const char *str, int *status)
{
	int	val;

	val = ft_atoi_error(str, status);
	// timeは1以上とする
	if (val <= 0)
		*status = false;
	return (val);
}


size_t	validate_eat_limit(const char *str, int *status)
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
	a->philo_count = validate_philo_num(argv[1], &status);
	a->die_t = validate_time(argv[2], &status);
	a->eat_t = validate_time(argv[3], &status);
	a->sleep_t = validate_time(argv[4], &status);
	if (argc == 6)
		a->meal_limits = ft_atoi_error(argv[5], &status);
	if (status == false)
		return (abort_philo_msg(ARGS_ERROR));
	return (true);
}
