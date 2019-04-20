//
// Created by Jasper Leann on 2019-04-18.
//
#include "fillit.h"

void 	run_fillit(char *f_name)
{
	t_list *tetros;

	tetros = read_file(f_name);

	char **map;

	solve_tetros(&map, tetros);

	output(map);
}