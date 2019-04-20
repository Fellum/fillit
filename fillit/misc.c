//
// Created by Jasper Leann on 2019-04-18.
//

#include "libft.h"

void	raise_error(char *desc)
{
	ft_putendl(desc);
	exit(1);
}

char	charify(unsigned char x, unsigned char y)
{
	return ((x & 15) << 4 | (y & 15));
}

void	uncharify(unsigned char *x, unsigned char *y, unsigned char c)
{
	*x = (c >> 4) | ((c & 8) << 4);
	*y = ((c & 8) << 4) | (c & 15);
}

void	printbits(unsigned char c)
{
	char cur;

	cur = 7;
	while (cur + 1)
		ft_putchar('0' + ((c >> cur--) & 1));
}