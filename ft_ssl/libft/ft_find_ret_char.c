/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_ret_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 02:04:28 by majones           #+#    #+#             */
/*   Updated: 2018/09/13 02:04:54 by majones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			ft_find_ret_char(char *src, int c)
{
	int i;

	i = 0;
	while (src[i])
	{
		if (src[i] == (char)c)
			return ((char)c);
		i++;
	}
	return (src[i]);
}
