/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shisaeki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:18:18 by shisaeki          #+#    #+#             */
/*   Updated: 2023/05/20 14:17:03 by shisaeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t len_needle;
	size_t i;
	size_t j;

	len_needle = ft_strlen(needle);
	if (len_needle == 0)
		return ((char *)haystack);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j])
		{
			if (j == len_needle)
				return ((char *)&haystack[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
