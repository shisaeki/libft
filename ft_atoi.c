/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shisaeki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:42:06 by shisaeki          #+#    #+#             */
/*   Updated: 2023/05/20 19:57:11 by shisaeki         ###   ########.fr       */
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

	sing = 1;
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
