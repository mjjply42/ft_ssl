/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 19:17:10 by majones           #+#    #+#             */
/*   Updated: 2018/05/12 00:32:41 by majones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	char	*it1;
	char	*it2;

	if (!*needle)
		return ((void *)haystack);
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			it1 = ((void *)haystack + 1);
			it2 = ((void *)needle + 1);
			while (*it1 && *it2 && *it1 == *it2)
			{
				++it1;
				++it2;
			}
			if (!*it2)
				return ((void *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
