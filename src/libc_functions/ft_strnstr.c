/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 13:52:22 by shinsaeki         #+#    #+#             */
/*   Updated: 2024/06/09 13:52:41 by shinsaeki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (*needle == '\0')
		return ((char *)haystack);
	while (len-- > 0)
	{
		i = 0;
		while (haystack[i] == needle[i])
		{
			if (needle[i + 1] == '\0')
				return ((char *)haystack);
			if (len <= i)
				return (NULL);
			i++;
		}
		if (haystack[i] == '\0')
			return (NULL);
		haystack++;
	}
	return (NULL);
}