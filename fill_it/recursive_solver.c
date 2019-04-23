/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_solver.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 21:33:09 by mdebbi            #+#    #+#             */
/*   Updated: 2019/04/21 21:33:54 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static int	insert(char **map, char *cords, t_cords cord, char symb)
{
	unsigned char	x;
	unsigned char	y;
	int				inserted;

	inserted = 0;
	if (symb != '.')
		while (inserted < 4)
		{
			uncharify(&x, &y, cords[inserted]);
			if (cord.y - y < 0 || cord.x - x < 0
					|| map[cord.y - y][cord.x - x] != '.')
				return (0);
			inserted++;
		}
	inserted = 0;
	while (inserted < 4)
	{
		uncharify(&x, &y, cords[inserted]);
		map[cord.y - y][cord.x - x] = symb;
		inserted++;
	}
	return (1);
}

int			try_solve(char **map, t_list *tetros)
{
	static char	symb = 'A';
	t_cords		cord;

	if (!tetros)
		return (1);
	cord.y = 0;
	while (map[cord.y])
	{
		cord.x = 0;
		while (map[cord.x])
		{
			if (insert(map, tetros->content, cord, symb))
			{
				symb++;
				if (try_solve(map, tetros->next))
					return (1);
				insert(map, tetros->content, cord, '.');
				symb--;
			}
			cord.x++;
		}
		cord.y++;
	}
	return (0);
}
