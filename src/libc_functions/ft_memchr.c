/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 23:53:16 by shinsaeki         #+#    #+#             */
/*   Updated: 2024/06/03 00:09:53 by shinsaeki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ret;
	size_t	i;

	ret = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*ret == (unsigned char)c)
			return ((void *)ret);
		ret++;
		i++;
	}
	return (NULL);
}