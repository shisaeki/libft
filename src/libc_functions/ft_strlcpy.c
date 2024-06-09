/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 00:13:18 by shinsaeki         #+#    #+#             */
/*   Updated: 2024/06/07 15:23:53 by shinsaeki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

size_t	ft_strlcpy(char * restrict dst, const char * restrict src, size_t dstsize)
{
	size_t	src_len;
	size_t	copy_len;

	src_len = ft_strlen(src);
	copy_len = (dstsize > 0) ? dstsize - 1 : 0;
	if (copy_len > src_len)
		copy_len = src_len;
	if (dstsize > 0)
	{
		ft_memcpy(dst, src, copy_len);
		dst[copy_len] = '\0';
	}
	
	return (src_len);
}