/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shisaeki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:42:06 by shisaeki          #+#    #+#             */
/*   Updated: 2023/05/21 19:43:07 by shisaeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int skip_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

long	get_long(const char *str, int sign)
{
	long nbr;
	size_t i;

	nbr = 0;
	i = 0;
	while ('0' <= str[i] && str[i] <= '9' && str[i] != '\0')
	{
		if (sign == 1)
		{
			if ((nbr == LONG_MAX / 10 && str[i] > LONG_MAX % 10 + '0')
				|| (nbr > LONG_MAX / 10))
				return (LONG_MAX);
		}
		else
		{
			if ((-1 * nbr ==  LONG_MIN / 10 && -1 * (str[i] - '0') < (LONG_MIN % 10))
				|| (-1 * nbr < LONG_MIN / 10))
				return (LONG_MIN);
		}
		nbr *= 10;
		nbr += str[i] - '0';
		i++;
	}
	return (sign * nbr);
}

int	ft_atoi(const char *str)
{
	int	sign;
	size_t i;

	sign = 1;
	i = 0;
	while (str[i] != '\0' && skip_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	return (get_long(&str[i], sign));
}

//#include <stdio.h>
//
//int main()
//{
//	printf("LONG_MAX + 1 EXP :%d\n", atoi("9223372036854775809"));
//	printf("LONG_MAX + 1 ACT :%d\n", ft_atoi("9223372036854775809"));
//	printf("LONG_MIN - 1 EXP :%d\n", atoi("-9223372036854775809"));
//	printf("LONG_MIN - 1 ACT :%d\n", ft_atoi("-9223372036854775809"));
//	printf("SIZE_MAX + 1 EXP :%d\n", atoi("18446744073709551616"));
//	printf("SIZE_MAX + 1 ACT :%d\n", ft_atoi("18446744073709551616"));
//	printf("SIZE_MAX - 1 EXP :%d\n", atoi("18446744073709551614"));
//	printf("SIZE_MAX - 1 ACT :%d\n", ft_atoi("18446744073709551614"));
//	return (0);
//}
