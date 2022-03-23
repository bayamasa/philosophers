/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:58:39 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/23 00:04:25 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	init_philo_attr(t_sim_stat *s, const char *argv[])
{
	size_t			i;
	size_t			philo_count;

	philo_count = ft_atoi(argv[NUMBER_OF_PHILOSOPHERS]);
	s->ph_attr = (t_philo_attr **)malloc(sizeof(t_philo_attr *) * philo_count);
	if (s->ph_attr == NULL)
		return (false);
	i = 0;
	while (i < philo_count)
	{
		s->ph_attr[i] = (t_philo_attr *)malloc(sizeof(t_philo_attr));
		if (s->ph_attr == NULL)
			return (false);
		s->ph_attr[i]->index = i;
		s->ph_attr[i]->num = i + 1;
		s->ph_attr[i]->start_t = 0;
		s->ph_attr[i]->ate_t = 0;
		s->ph_attr[i]->phc = s->ph_config;
		s->ph_attr[i]->pc = s->pub_config;
		i++;
	}
	return (true);
}

bool	init_monitor_attr(t_sim_stat *s)
{
	t_monitor_attr	*m_attr;

	m_attr = (t_monitor_attr *)malloc(sizeof(t_monitor_attr));
	if (m_attr == NULL)
		return (false);
	m_attr->pc = s->pub_config;
	m_attr->ph_attr = s->ph_attr;
	s->m_attr = m_attr;
	return (true);
}

bool	init_pub_config(t_public_config *pc, const char *argv[])
{
	pc->eat_count = 0;
	pc->is_anyone_dead = false;
	pc->philo_count = ft_atoi(argv[NUMBER_OF_PHILOSOPHERS]);
	pc->eat_limit_surpassed = false;
	if (argv[TIMES_PHILO_MUST_EAT] != NULL)
	{
		pc->eat_limit_exist = true;
		pc->eat_limit = ft_atoi(argv[TIMES_PHILO_MUST_EAT]);
	}
	else
	{
		pc->eat_limit_exist = false;
		pc->eat_limit = 0;
	}
	pc->die_t = ft_atoi(argv[TIME_TO_DIE]);
	if (pthread_mutex_init(&(pc->m_mutex), NULL) == -1)
		return (false);
	return (true);
}

bool	init_philo_config(t_philo_config *ph, const char *argv[])
{
	size_t	i;

	i = 0;
	if (ph == NULL)
		return (false);
	ph->fork_count = ft_atoi(argv[NUMBER_OF_PHILOSOPHERS]);
	ph->fork_mutex = (pthread_mutex_t *) \
		malloc(sizeof(pthread_mutex_t) * ph->fork_count);
	if (ph->fork_mutex == NULL)
		return (false);
	while (i < ph->fork_count)
	{
		if (pthread_mutex_init(&(ph->fork_mutex[i]), NULL) == -1)
			return (false);
		i++;
	}	
	ph->is_fork_taken = (bool *)malloc(sizeof(bool) * ph->fork_count);
	if (ph->is_fork_taken == NULL)
		return (false);
	while (i < ph->fork_count)
		ph->is_fork_taken[i++] = false;
	ph->eat_t = ft_atoi(argv[TIME_TO_EAT]) * 1000LL;
	ph->sleep_t = ft_atoi(argv[TIME_TO_SLEEP]) * 1000LL;
	return (true);
}

bool	init_all_config(t_sim_stat *s, const char *argv[])
{
	t_philo_config	*ph_config;
	t_public_config	*pub_config;

	ph_config = (t_philo_config *)malloc(sizeof(t_philo_config));
	if (!init_philo_config(ph_config, argv))
		return (false);
	pub_config = (t_public_config *)malloc(sizeof(t_public_config));
	if (!init_pub_config(pub_config, argv))
		return (false);
	s->ph_config = ph_config;
	s->pub_config = pub_config;
	return (true);
}
