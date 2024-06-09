/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:51:56 by shinsaeki         #+#    #+#             */
/*   Updated: 2024/06/09 12:31:40 by shinsaeki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

size_t	ft_strlcat(char * restrict dst, const char * restrict src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	cat_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	cat_len = dstsize - dst_len - 1;
	if (cat_len > src_len)
		cat_len = src_len;
	i = 0;
	while (i < cat_len && src[i] != '\0')
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';

	return (dst_len + src_len);
}