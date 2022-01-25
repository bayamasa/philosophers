/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:06:06 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/25 16:45:23 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	return (0);
}

size_t	ft_atoi_error(const char *str, int *status)
{
	long long	ret;

	if (ft_strlen(str) == 0 || !ft_isdigit(*str))
		*status = false;
	if (*str == '0')
		if (ft_strlen(str) != 1)
			*status = false;
	ret = ft_strtoll(str, status);
	return (ret);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;
	size_t	i;

	if (!s)
		return ;
	i = 0;
	len = ft_strlen(s);
	while (len > STR_BUFF_SIZE)
	{
		write(fd, s + i, STR_BUFF_SIZE);
		i = i + STR_BUFF_SIZE;
		len = len - STR_BUFF_SIZE;
	}
	write(fd, s + i, len);
}

int	ft_isspace(char a)
{
	if (a == '\t' || a == '\n' || a == '\v'
		|| a == ' ' || a == '\r' || a == '\f' )
		return (1);
	return (0);
}

long long	ft_strtoll(const char *str, int *status)
{
	size_t		i;
	long long	num;
	int			sign;

	num = 0;
	i = 0;
	sign = 1;
	if (!str)
		return (0);
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((num * 10 + (str[i] - '0')) / 10 != num)
			*status = false;
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		*status = false;
	return ((num * sign));
}
