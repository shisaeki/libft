/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shisaeki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:11:37 by shisaeki          #+#    #+#             */
/*   Updated: 2023/05/20 13:51:16 by shisaeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(
		char *restrict dst,
		const char *restrict src,
		size_t dstsize)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
	i = 0;
	while (i < dstsize - 1)
	{
		if (src[i] == '\0')
			break;
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
