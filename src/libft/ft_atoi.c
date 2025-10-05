/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamarin- <mamarin-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:13:00 by dukim             #+#    #+#             */
/*   Updated: 2025/09/29 09:57:53 by mamarin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_overflow(long sum, int minus_cnt, char *error)
{
	if (minus_cnt)
	{
		if (sum > 2147483648LL)
		{
			*error = 1;
			return (1);
		}
	}
	else
	{
		if (sum > 2147483647LL)
		{
			*error = 1;
			return (1);
		}
	}
	return (0);
}

static long	parse_digits(const char *s, int minus_cnt, char *error)
{
	long		sum;

	sum = 0;
	while (*s)
	{
		if (!ft_isdigit(*s))
		{
			*error = 1;
			return (0);
		}
		sum = sum * 10 + (*s - '0');
		if (check_overflow(sum, minus_cnt, error))
			return (0);
		s++;
	}
	return (sum);
}

int	ft_atoi(const char *nptr, char *error)
{
	int		minus_cnt;
	long	result;

	minus_cnt = 0;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			minus_cnt = 1;
		nptr++;
		if (*nptr == '\0')
			return (*error = 1, 0);
	}
	result = parse_digits(nptr, minus_cnt, error);
	if (minus_cnt)
		result = -result;
	return (result);
}
