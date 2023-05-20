/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shisaeki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:36:31 by shisaeki          #+#    #+#             */
/*   Updated: 2023/05/19 15:33:54 by shisaeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	uc;
	unsigned char	*ptr;
	size_t			i;

	uc = (unsigned char)c;
	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*ptr == uc)
			return ((void *)ptr);
		ptr++;
		i++;
	}
	return (NULL);
}

//#include <string.h>
//#include <stdio.h>
//
//int main()
//{
//	char *s = "libft-test-tokyo\0\0\0acdfg\0\0\0\0\0";
//
//	char *c_expected = (char *)memchr(s, 'z', 30);
//	char *c_actual = (char *)ft_memchr(s, 'z', 30);
//	printf("%p\n", c_expected);
//	printf("%p\n", c_actual);
//}
