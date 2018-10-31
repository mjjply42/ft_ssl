/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bintohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 20:56:17 by majones           #+#    #+#             */
/*   Updated: 2018/10/12 15:39:24 by majones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_bintodec(int binary)
{
	int decimal;
	int i;
	int remainder;

	decimal = 0;
	i = 1;
	remainder = 0;
	while (binary != 0)
	{
		remainder = binary % 10;
		decimal = decimal + remainder * i;
		i = i * 2;
		binary = binary / 10;
	}
	return (decimal);
}
