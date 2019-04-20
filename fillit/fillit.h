//
// Created by Jasper Leann on 2019-04-18.
//

#ifndef FILLIT_FILLIT_H
# define FILLIT_FILLIT_H
# include "libft.h"
void 	run_fillit(char *f_name);

void	*read_file(char *f_name);
void	solve_tetros(char ***map, t_list *tetros);
void 	output(void *map);


int		try_solve(char **map, t_list *tetros);

void	raise_error(char *desc);
void	uncharify(unsigned char *x, unsigned char *y, unsigned char c);
char	charify(unsigned char x, unsigned char y);
void	printbits(unsigned char c);
#endif
