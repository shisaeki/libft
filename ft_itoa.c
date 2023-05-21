/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shisaeki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:29:08 by shisaeki          #+#    #+#             */
/*   Updated: 2023/05/21 17:15:07 by shisaeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	n_pow(int n)
{
	int pow;

	pow = 1;
	while (n)
	{
		pow *= 10;
		n--;
	}
	return(pow);
}

#include <stdio.h>

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
	while (i < num_digits)
	{
		str[i] = n / n_pow(num_digits - i - 1) + '0';
		n = n % n_pow(num_digits - i - 1) + '0';
		i++;
		printf("%zu\n", i);
	}
	str[i] = '\0';
	return (str);
}

int main()
{
	int n = 123;
	printf("%s\n", ft_itoa(n));
}

