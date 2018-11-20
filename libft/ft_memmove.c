/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 19:40:28 by majones           #+#    #+#             */
/*   Updated: 2018/06/11 10:26:08 by majones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dtmp;
	const char	*stmp;

	dtmp = (char *)dst;
	stmp = (char *)src;
	if (stmp < dtmp)
		while (len--)
			dtmp[len] = stmp[len];
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
