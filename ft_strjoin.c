/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shisaeki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:51:44 by shisaeki          #+#    #+#             */
/*   Updated: 2023/05/20 18:00:33 by shisaeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	char *result;
	size_t len_s1;
	size_t len_s2;
	size_t i;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	i = 0;
	while (*s1 != '\0')
	{
		result[i] = *s1;
		i++;
		s1++;
	}
	while (*s2 != '\0')
	{
		result[i] = *s2;
		i++;
		s2++;
	}
	result[i] = '\0';
	return (result);
}
