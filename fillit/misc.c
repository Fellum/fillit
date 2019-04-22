/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:09:23 by mdebbi            #+#    #+#             */
/*   Updated: 2019/04/22 16:09:43 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			raise_error(char *desc)
{
	ft_putendl(desc);
	exit(1);
}

char			charify(unsigned char x, unsigned char y)
{
	return ((x & 15U) << 4U | (y & 15U));
}

void			uncharify(unsigned char *x, unsigned char *y, unsigned char c)
{
	*x = (c >> 4U) | ((c & 8U) << 4U);
	*y = ((c & 8U) << 4U) | (c & 15U);
}

void			printbits(unsigned char c)
{
	unsigned char cur;

	cur = 8;
	while (cur-- > 0)
		ft_putchar('0' + ((c >> cur) & 1U));
}

unsigned int	ft_abs(int nbr)
{
	return ((nbr < 0) ? -nbr : nbr);
}
