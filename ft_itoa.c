/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shisaeki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:29:08 by shisaeki          #+#    #+#             */
/*   Updated: 2023/05/21 20:01:22 by shisaeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t get_num_digits(int n)
{
	int nbr;
	size_t i;

	nbr = n;
	i = 0;
	if (nbr < 0)
		i++;
	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char *ft_itoa(int n)
{
	char *str;
	size_t num_digits;
	size_t i;

	num_digits = get_num_digits(n);
	str = (char *)malloc(sizeof(char) * (num_digits + 1));
	if (!str)
		return (NULL);
	str[num_digits] = '\0';
	while (0 < n)
	{
		str[num_digits - 1] = n % 10;
		n /= 10;
		num_digits--;
	}
	return (str);
}

#include <stdio.h>

int main()
{
	int n = 123;
	printf("%s\n", ft_itoa(n));
}

