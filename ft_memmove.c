/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shisaeki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:44:32 by shisaeki          #+#    #+#             */
/*   Updated: 2023/05/24 16:56:30 by shisaeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t size)
{
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;
	size_t			i;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	ptr_s1 = (unsigned char *)s1;
	ptr_s2 = (unsigned char *)s2;
	i = -1;
	if (ptr_s1 <= ptr_s2)
	{
		while (++i < size)
			ptr_s1[i] = ptr_s2[i];
	}
	else
	{
		while (0 < size)
		{
			ptr_s1[size - 1] = ptr_s2[size - 1];
			size--;
		}
	}
	return (s1);
}
