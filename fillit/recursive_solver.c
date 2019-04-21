//
// Created by Jasper Leann on 2019-04-18.
//

#include "libft.h"
#include "fillit.h"

int	insert(char **map, char *cords, char x, char y, char symb)//0 -fail, 1-suckass
{
	unsigned char xcord;
	unsigned char ycord;
	int inserted;

	inserted = 0;
	if (symb != '.')
		while (inserted < 4)
		{
			uncharify(&xcord, &ycord, cords[inserted]);
			if (y - ycord < 0 || x - xcord < 0
								|| map[y - ycord][x - xcord] != '.')
				return (0);
			inserted++;
		}
	inserted = 0;
	while (inserted < 4)
	{
		uncharify(&xcord, &ycord, cords[inserted]);
		map[y - ycord][x - xcord] = symb;
		inserted++;
	}
	return (1);
}



int		try_solve(char **map, t_list *tetros)
{
	static char symb = 'A';
	char x, y;
	if (!tetros)
		return (1);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[x])
		{
			if (insert(map, tetros->content, x, y, symb))
			{
				symb++;
				if (try_solve(map, tetros->next))
					return (1);
				insert(map, tetros->content, x, y, '.');
				symb--;
			}
			x++;
		}
		y++;
	}
	return (0);
}
