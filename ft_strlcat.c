/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shisaeki <shisaeki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:57:02 by shisaeki          #+#    #+#             */
/*   Updated: 2023/05/19 18:05:15 by shisaeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include "libft.h"

size_t	ft_strlcat(
	char * restrict dst,
	const char * restrict src,
	size_t dstsize)
{
	size_t i;
	size_t len_max;
	size_t len_dst;
	size_t len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (dstsize <= len_dst)
		return (dstsize + len_src);
	len_max = dstsize - len_dst;
	i = 0;
	while (i < len_max)
	{
		if (src[i] == '\0')
			break;
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}
