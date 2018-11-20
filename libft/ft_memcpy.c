/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:43:52 by majones           #+#    #+#             */
/*   Updated: 2018/06/11 10:59:26 by majones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dtmp;
	char		*stmp;
	size_t		i;

	dtmp = (char *)dst;
	stmp = (char *)src;
	i = -1;
	while (++i < n)
		*(dtmp + i) = *(stmp + i);
	return (dst);
}
