/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_till_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 17:43:17 by majones           #+#    #+#             */
/*   Updated: 2018/04/26 17:54:53 by majones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_till_zero(char *str)
{
	int count;
	int i;

	count = 0;
	while (str && *str)
	{
		str++;
		count++;
	}
	i = count;
	while (i != 0)
	{
		str--;
		i--;
	}
	return (count);
}
