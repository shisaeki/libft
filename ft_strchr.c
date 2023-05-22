/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shisaeki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:45:12 by shisaeki          #+#    #+#             */
/*   Updated: 2023/05/22 17:56:58 by shisaeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*ptr;
	unsigned char	uc;
	size_t			len;
	size_t			i;

	ptr = NULL;
	uc = (unsigned char)c;
	len = ft_strlen(s);
	i = 0;
	while (i <= len)
	{
		if (*s == uc)
		{
			ptr = (char *)(s);
			return (ptr);
		}
		s++;
		i++;
	}
	return (ptr);
}
