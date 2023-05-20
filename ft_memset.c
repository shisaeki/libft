/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shisaeki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:40:48 by shisaeki          #+#    #+#             */
/*   Updated: 2023/05/18 16:41:29 by shisaeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t size)
{
	unsigned char	uc;
	unsigned char	*ptr;
	size_t			i;

	uc = (unsigned char)c;
	ptr = (unsigned char *)s;
	i = 0;
	while (i < size)
	{
		ptr[i] = uc;
		i++;
	}
	return (s);
}
