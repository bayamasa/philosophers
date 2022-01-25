/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:42:14 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/25 16:28:58 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	abort_philo_msg(char *msg)
{
	ft_putstr_fd(ERROR, STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	return (EXIT_FAILURE);
}

