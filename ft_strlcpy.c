/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shisaeki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:11:37 by shisaeki          #+#    #+#             */
/*   Updated: 2023/05/19 17:48:34 by shisaeki         ###   ########.fr       */
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
	i = 0;
	while (i < dstsize - 1)
	{
		if (src[i] == '\0')
			break;
		dst[i] = src[i];
		i++;
	}
	dst[dstsize] = '\0';
	return (len);
}

#include <stdio.h>
#include <string.h>

int main()
{
	char *dst1 = calloc(10, sizeof(char));
	char *dst2 = calloc(10, sizeof(char));
	char *src1 = calloc(10, sizeof(char));
	char *src2 = calloc(10, sizeof(char));
	memset(src1, 'z', 9);
	memset(src2, 'z', 9);

	size_t expected = strlcpy(dst1, src1, 0);
	size_t actual = ft_strlcpy(dst2, src2, 0);
	printf("%zu\n", expected);
	printf("%zu\n", actual);
}
