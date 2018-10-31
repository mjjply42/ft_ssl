/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 17:11:28 by majones           #+#    #+#             */
/*   Updated: 2018/06/11 10:24:55 by majones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*str;
	size_t	i;

	i = -1;
	str = dst;
	while (++i < len)
	{
		if (*src)
			*dst++ = *src++;
		else
			*dst++ = 0;
	}
	return (str);
}
