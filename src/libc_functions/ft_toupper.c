/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:21:59 by shinsaeki         #+#    #+#             */
/*   Updated: 2024/05/29 17:30:01 by shinsaeki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_toupper(int c)
{
	if (!ft_islower(c))
		return c;
	return (c - 32);
}