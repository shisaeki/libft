/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shisaeki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:02:44 by shisaeki          #+#    #+#             */
/*   Updated: 2023/05/20 18:26:34 by shisaeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_exist_char(char c, char const *set)
{
	while (*set != '\0')
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

size_t	count_char(char const *s1, char const *set)
{
	size_t count;
	size_t i;

	count = 0;
	i = 0;
	while (s1[i] != '\0')
	{
		if (is_exist_char(s1[i], set))
			count++;
		i++;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char *result;
	size_t len_s1;
	size_t count;
	size_t i;

	len_s1 = ft_strlen(s1);
	count = count_char(s1, set);
	result = (char *)malloc(sizeof(char) * (len_s1 - count + 1));
	i = 0;
	while (i < len_s1 - count)
	{
		if (!is_exist_char(*s1, set))
			result[i] = *s1;
		i++;
		s1++;
	}
	return (result);
}
