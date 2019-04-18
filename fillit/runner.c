//
// Created by Jasper Leann on 2019-04-18.
//
#include "fillit.h"

void 	run_fillit(char *f_name)
{
	void *tetros;

	tetros = read_file(f_name);

	void *map;

	solve_tetros(&map, tetros);

	output(map);
}