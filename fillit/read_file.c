//
// Created by Jasper Leann on 2019-04-18.
//

#include "libft.h"
#include <fcntl.h>
#include "fillit.h"

void 	read_tetro(const int fd, char *res)
{
	char *line;
	char cur_x;
	char cur_y;
	char cur_block;

	cur_y = 0;
	cur_x = 0;
	cur_block = 0;
	while (cur_y < 4 && ft_get_next_line(fd, &line) == GNL_SUCCES)
	{
		cur_x = 0;
		while (cur_x < 4 && line[cur_x])
		{
			if (line[cur_x] == BLOCK_SYMBOL)
			{
				if (cur_block == 4)
					raise_error("INVALID MAP");
				res[cur_block++] = charify(cur_x, cur_y);
			}
			else if (line[cur_x] != BLANK_SYMBOL)
				raise_error("INVALID MAP");
			cur_x++;
		}
		if (line[cur_x])
			raise_error("INVALID MAP");
		cur_y++;
		free(line);
	}
	if (cur_y != 4 && cur_x != 4 && cur_block != 4)
		raise_error("INVALID MAP");
}

void	process_tetro(char *t)
{
	char			cur;
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

static unsigned int ft_abs(int nbr)
{
	return ((nbr < 0) ? -nbr : nbr);
}

int is_valid_tetro(char tetro[4])
{
	int i;
	int j;
	unsigned char unchar[4][2];
	int bounds;

	bounds = 0;
	i = 0;
	while (i < 4)
	{
		uncharify(&unchar[i][0], &unchar[i][1], tetro[i]);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i != j && (ft_abs(unchar[i][0] - unchar[j][0]) + ft_abs(unchar[i][1] - unchar[j][1]) == 1))
				bounds++;
			j++;
		}
		i++;
	}
	return ((bounds == 6 || bounds == 8) ?  0 : 1);
}

t_list	*read_file(char *f_name)
{
	int		fd;
	int 	read_res;
	char	cur_tetro[4];
	char	*line;
	t_list	*result;

	result = NULL;
	if ((fd = open(f_name, O_RDONLY)) <= 0)
		raise_error("FILE ERROR!!");
	read_tetro(fd, cur_tetro);
	if (!is_valid_tetro(cur_tetro))
		raise_error("INVALID INPUT USAGE:KEK");
	process_tetro(cur_tetro);
	ft_lstaddend(&result, ft_lstnew(cur_tetro, 8));
	while (((read_res = ft_get_next_line(fd, &line) == GNL_SUCCES)) && (!line[0]))
	{
		free(line);
		read_tetro(fd, cur_tetro);
		if (!is_valid_tetro(cur_tetro))
			raise_error("INVALID INPUT USAGE:KEK");
		process_tetro(cur_tetro);
		ft_lstadd(&result, ft_lstnew(cur_tetro, 8));
	}
	if (read_res == GNL_ERROR || (read_res == GNL_SUCCES && line[0]))
		raise_error("ERROR");
	return (result);
}
