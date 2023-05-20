/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shisaeki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:19:14 by shisaeki          #+#    #+#             */
/*   Updated: 2023/05/20 16:30:18 by shisaeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (0 <= n && n < 10)
		ft_putchar_fd(n + '0', fd);
	else if (10 <= n)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10 + '0', fd);
	}
	else
	{
		if (n == INT_MIN)
			ft_putstr_fd("-2147483648", fd);
		else
		{
			ft_putchar_fd('-', fd);
			ft_putnbr_fd(-1 * n, fd);
		}
	}
}
