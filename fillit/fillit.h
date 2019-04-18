//
// Created by Jasper Leann on 2019-04-18.
//

#ifndef FILLIT_FILLIT_H
#define FILLIT_FILLIT_H
void 	run_fillit(char *f_name);

void	*read_file(char *f_name);
void	solve_tetros(void **map, void *tetros);
void 	output(void *map);


int		try_solve(void *map, void *tetros);

void	raise_error(char *desc);
#endif
