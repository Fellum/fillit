//
// Created by Jasper Leann on 2019-04-18.
//

#include "fillit.h"
#include "libft.h"

static int calc_min(void *tetros)
{
	return (4);
}

static void * create_map(int size)
{
	return (NULL);
}

static void	free_map(void **map, int size)
{
	free(*map);
	*map = NULL;
}

void	solve_tetros(void **map, void *tetros)
{
	int cur_size;
	int res;

	cur_size = calc_min(tetros);
	if (!(*map = create_map(cur_size)))
		raise_error("ALLOC ERROR");
	while (try_solve(*map, tetros) == 0)
	{
		free_map(map, cur_size++);
		if (!(*map = create_map(cur_size)))
			raise_error("ALLOC ERROR");
	}
}

