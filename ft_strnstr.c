/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shisaeki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:18:18 by shisaeki          #+#    #+#             */
/*   Updated: 2023/05/20 15:44:06 by shisaeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//size_t	ft_strlen(const char *s)
//{
//	size_t	len;
//
//	len = 0;
//	while (s[len] != '\0')
//		len++;
//	return (len);
//}

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t len_needle;
	size_t i;
	size_t j;

	len_needle = ft_strlen(needle);
	if (len_needle == 0)
		return ((char *)haystack);
	i = 0;
	while (i < len && haystack[i] != '\0')
	{
		j = 0;
		while (haystack[i + j] == needle[j])
		{
			if (j == len_needle - 1)
				return ((char *)(haystack + i));
			j++;
		}
		i++;
	}
	return (NULL);
}

//#include <string.h>
//#include <stdio.h>
//
//int main()
//{
//	char *s1 = "bacdefghi";
//	char *s2 = "cde";
//	char *expected;
//	char *actual;
//
//	expected = strnstr(s1, s2, 5);
//	actual = ft_strnstr(s1, s2, 5);
//
//	printf("%s\n", expected);
//	printf("%s\n", actual);
//	return (0);
//}
