/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:42:14 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/21 20:31:36 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	abort_philo_msg(char *msg)
{
	ft_putstr_fd(ERROR, STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	return (false);
}

bool	abort_philo_msg_with_free(char *msg, t_sim_stat *ph)
{
	// free_all(ph);
	(void)ph;
	ft_putstr_fd(ERROR, STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	return (false);
}

void	free_all(t_sim_stat *s)
{
	(void)s;
	// if (ph->p_attr != NULL)
	// 	free(ph->p_attr);
	// if (ph->is_fork_taken != NULL)
	// 	free(ph->is_fork_taken);
	// if (ph->fork_mutex != NULL)
	// 	free(ph->fork_mutex);
}
