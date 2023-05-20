/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shisaeki <shisaeki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:57:02 by shisaeki          #+#    #+#             */
/*   Updated: 2023/05/20 14:06:31 by shisaeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include "libft.h"

size_t	ft_strlcat(
	char * restrict dst,
	const char * restrict src,
	size_t dstsize)
{
	char *d;
	const char *s;
	size_t n;
	size_t len_dst;

	d = dst;
	s = src;
	n = dstsize;
	while (n-- != 0 && *d != '\0')
		d++;
	len_dst = d - dst;
	n = dstsize - len_dst;
	if (n == 0)
		return (len_dst + ft_strlen(s));
	while (*s != '\0')
	{
		if (n != 1)
		{
			*d = *s;
			d++;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (len_dst + (s - src));
}
