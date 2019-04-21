//
// Created by Jasper Leann on 2019-04-18.
//

#ifndef FILLIT_FILLIT_H
# define FILLIT_FILLIT_H
# include "libft.h"


#define BLOCK_SYMBOL '#'

#define BLANK_SYMBOL '.'
#define USAGE "usage: ./fillit source_file"
#define INVALID_TETR "Each block of a Tetrimino must touch at least one other block on any of his 4 sides (up, down, left and right)."
#define FILE_ERROR "No such file or directory"
#define MAP_ERROR "Invalid Tetrimino\nUsage:\n• Precisely 4 lines of 4 characters, each followed by a new line (well... a 4x4 square).\n• A Tetrimino is a classic piece of Tetris composed of 4 blocks.\n• Each character must be either a block character(’#’ ) or an empty character (’.’).\n• Each block of a Tetrimino must touch at least one other block on any of his 4 sides (up, down, left and right)."
#define INVALID_TETRIMINO_NUMBER "File should contain between 1 and 26 Tetriminos."

typedef struct {
	int x;
	int y;
} 		t_cords;

void 	run_fillit(char *f_name);

t_list	*read_file(char *f_name);
void	solve_tetros(char ***map, t_list *tetros);
void 	output(char **map);


int		try_solve(char **map, t_list *tetros);

void	raise_error(char *desc);
void	uncharify(unsigned char *x, unsigned char *y, unsigned char c);
char	charify(unsigned char x, unsigned char y);
void	printbits(unsigned char c);
#endif
