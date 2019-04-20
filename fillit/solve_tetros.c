//
// Created by Jasper Leann on 2019-04-18.
//

#include "fillit.h"
#include "libft.h"

static char **create_map(int size)
{
	char **map;
	int i;
	int j;

	map = (char**)malloc(sizeof(char*) * (size + 1));
	map[size] = 0;
	i = 0;
	while (i < size)
	{
		map[i] = (char*)malloc(size + 1);
		map[i][size] = 0;
		j = 0;
		while (j < size)
			map[i][j++] = '.';
		i++;
	}
	return (map);
}



static void	free_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

int calc_min_size(int nbr)
{
	int i;

	nbr = nbr * 4;
	i = 1;
	while (i * i <= nbr)
	{
		if (i * i == nbr)
			return (i);
		i++;
	}
	return (i - 1);
}

void	solve_tetros(char ***map, t_list *tetros)
{
	int min_size;
	int tetr_cnt;

	tetr_cnt = ft_lstlen(tetros);
	min_size = calc_min_size(tetr_cnt);
	if (!(*map = create_map(min_size)))
		raise_error("ALLOC ERROR");
	while (try_solve(*map, tetros) == 0)
	{
		free_map(*map);
		if (!(*map = create_map(++min_size)))
			raise_error("ALLOC ERROR");
	}
}

