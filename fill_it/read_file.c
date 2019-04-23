/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 15:36:40 by jleann            #+#    #+#             */
/*   Updated: 2019/04/22 15:36:41 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include "fillit.h"

static void	read_tetro(const int fd, char *res)
{
	char	*line;
	int		cur_block;
	t_cords cords;

	cords.x = 0;
	cur_block = 0;
	cords.y = -1;
	while (++cords.y < 4 && ft_get_next_line(fd, &line) == GNL_SUCCESS)
	{
		cords.x = -1;
		while (++cords.x < 4 && line[cords.x])
			if (line[cords.x] == BLOCK_SYMBOL)
			{
				if (cur_block == 4)
					raise_error(MAP_ERROR);
				res[cur_block++] = charify(cords.x, cords.y);
			}
			else if (line[cords.x] != BLANK_SYMBOL)
				raise_error(MAP_ERROR);
		if (line[cords.x] || cords.x != 4)
			raise_error(MAP_ERROR);
		free(line);
	}
	if (cords.y != 4 || cords.x != 4 || cur_block != 4)
		raise_error(MAP_ERROR);
}

static void	process_tetro(char *t)
{
	int				cur;
	unsigned char	max_c[2];
	unsigned char	cur_c[2];

	max_c[0] = 0;
	max_c[1] = 0;
	cur = 0;
	while (cur < 4)
	{
		uncharify(cur_c, cur_c + 1, t[cur]);
		if (cur_c[0] > max_c[0])
			max_c[0] = cur_c[0];
		if (cur_c[1] > max_c[1])
			max_c[1] = cur_c[1];
		cur++;
	}
	cur = 0;
	while (cur < 4)
	{
		uncharify(cur_c, cur_c + 1, t[cur]);
		t[cur] = charify(max_c[0] - cur_c[0], max_c[1] - cur_c[1]);
		cur++;
	}
}

static int	is_valid_tetro(char tetro[4])
{
	int				i;
	int				j;
	unsigned char	unchar[4][2];
	int				bounds;

	bounds = 0;
	i = -1;
	while (++i < 4)
		uncharify(&unchar[i][0], &unchar[i][1], tetro[i]);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i != j && (ft_abs(unchar[i][0] - unchar[j][0])
					+ ft_abs(unchar[i][1] - unchar[j][1]) == 1))
				bounds++;
			j++;
		}
		i++;
	}
	return ((bounds == 6 || bounds == 8) ? 1 : 0);
}

static void	tetro_read_process_add(int fd, char cur_tetro[4], t_list **result)
{
	t_list	*tmp;

	read_tetro(fd, cur_tetro);
	if (!is_valid_tetro(cur_tetro))
		raise_error(INVALID_TETR);
	process_tetro(cur_tetro);
	if (!(tmp = ft_lstnew(cur_tetro, 8)))
		raise_error(MAP_ERROR);
	ft_lstaddend(result, tmp);
}

t_list		*read_file(char *f_name)
{
	int		fd;
	int		read_res;
	char	cur_tetro[4];
	char	*line;
	t_list	*result;

	line = NULL;
	result = NULL;
	if ((fd = open(f_name, O_RDONLY)) <= 0)
		raise_error(FILE_ERROR);
	tetro_read_process_add(fd, cur_tetro, &result);
	while (((read_res = ft_get_next_line(fd, &line) == GNL_SUCCESS))
														&& (!line[0]))
	{
		free(line);
		tetro_read_process_add(fd, cur_tetro, &result);
	}
	if (read_res == GNL_ERROR || (read_res == GNL_SUCCESS && line[0]))
		raise_error(MAP_ERROR);
	if (ft_lstlen(result) > 26)
		raise_error(INVALID_TETRIMINO_NUMBER);
	return (result);
}
