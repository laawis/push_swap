/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaollier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:45:16 by gaollier          #+#    #+#             */
/*   Updated: 2023/06/30 11:19:57 by gaollier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <limits.h>
#include <errno.h>

#include "libft.h"

static int	check_limits(int digit, int res, int sign);

int	ft_atoi(const char *s)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	sign = 1;
	res = 0;
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		if (check_limits(s[i] - '0', res, sign))
			return (check_limits(s[i] - '0', res, sign));
		res = res * 10 + s[i] - '0';
		i++;
	}
	return (res * sign);
}

static int	check_limits(int digit, int res, int sign)
{
	if ((INT_MAX / 10 < res * sign) || (INT_MAX - digit < res * 10 * sign))
	{
		errno = ERANGE;
		return (INT_MAX);
	}
	if ((INT_MIN / 10 > res * sign) || (INT_MIN + digit > res * 10 * sign))
	{
		errno = ERANGE;
		return (INT_MIN);
	}
	return (0);
}
