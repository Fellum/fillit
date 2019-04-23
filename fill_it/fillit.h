/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:11:01 by mdebbi            #+#    #+#             */
/*   Updated: 2019/04/22 16:11:03 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_FILLIT_H
# define FILLIT_FILLIT_H
# include "libft.h"
# define BLOCK_SYMBOL '#'
# define BLANK_SYMBOL '.'
# define USAGE "usage: ./fillit source_file"
# define INVALID_TETR "error"
# define FILE_ERROR "error"
# define MAP_ERROR "error"
# define INVALID_TETRIMINO_NUMBER "error"

typedef	struct	s_cords
{
	int			x;
	int			y;
}				t_cords;
void			run_fillit(char *f_name);
t_list			*read_file(char *f_name);
void			solve_tetros(char ***map, t_list *tetros);
void			output(char **map);
int				try_solve(char **map, t_list *tetros);
void			raise_error(char *desc);
void			uncharify(unsigned char *x, unsigned char *y, unsigned char c);
char			charify(unsigned char x, unsigned char y);
unsigned int	ft_abs(int nbr);
void			free_map(char **map);
void			ft_freelst(t_list **head);
#endif
