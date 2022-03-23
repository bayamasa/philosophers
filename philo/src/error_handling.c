/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:42:14 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/23 15:38:31 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	abort_philo_msg(char *msg)
{
	ft_putstr_fd(ERROR, STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	return (false);
}

void	free_philo_config(t_philo_config *ph_config)
{
	size_t	i;

	i = 0;
	free(ph_config->is_fork_taken);
	free(ph_config->fork_mutex);
}

void	free_philo_attr(t_philo_attr **ph_attr, size_t philo_count)
{
	size_t	i;

	i = 0;
	while (i < philo_count)
	{
		free(ph_attr[i]);
		i++;
	}
	free(ph_attr);
}

void	free_all(t_sim_stat *s)
{
	if (s->ph_config != NULL)
	{
		free_philo_config(s->ph_config);
		free(s->ph_config);
	}
	if (s->ph_attr != NULL)
		free_philo_attr(s->ph_attr, s->pub_config->philo_count);
	if (s->pub_config != NULL)
		free(s->pub_config);
	if (s->m_attr != NULL)
		free(s->m_attr);
}
