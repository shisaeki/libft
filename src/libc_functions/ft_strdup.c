/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 23:57:22 by shinsaeki         #+#    #+#             */
/*   Updated: 2024/06/07 00:08:07 by shinsaeki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ret;
	size_t	len;
	size_t	i;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	ret = (char *)malloc(len * sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = s1[i];
		i++;
	}
	ret[len] = '\0';
	
	return (ret);
}