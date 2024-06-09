/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 23:48:15 by shinsaeki         #+#    #+#             */
/*   Updated: 2024/06/06 23:58:30 by shinsaeki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ret;
	size_t	i;

	ret = (char *)malloc(count * size);
	if (!ret)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		ret[i] = 0;
		i++;
	}
	return (ret);
}