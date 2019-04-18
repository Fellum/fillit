//
// Created by Jasper Leann on 2019-04-18.
//

#include "libft.h"

char	**try_place(char **map, int )
{

}

int		try_solve(char **map, t_list *tetros)
{
	t_list *tetrstart;

	tetrstart = tetros;
	if (!tetros)
		return (1);
	while (tetros)
	{
		newmap = try_place(map, tetros->content);
		if (newmap)
		{
			if (try_solve(newmap, pop(tetros, ??)))
				return (1);
		}
		tetros = tetros->next;
	}
	return (0);
}
