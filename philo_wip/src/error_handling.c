/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:42:14 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/31 22:44:48 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	abort_philo_msg(char *msg)
{
	ft_putstr_fd(ERROR, STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	return (false);
}

bool	abort_philo_msg_with_free(char *msg, t_sim_stat *s)
{
	free_all(s);
	ft_putstr_fd(ERROR, STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	return (false);
}

void	free_all(t_sim_stat *s)
{
	if (s->p_attr != NULL)
		free(s->p_attr);
	if (s->is_fork_taken != NULL)
		free(s->is_fork_taken);
	if (s->fork_mutex != NULL)
		free(s->fork_mutex);
}
