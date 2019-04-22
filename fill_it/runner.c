/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 15:34:54 by mdebbi            #+#    #+#             */
/*   Updated: 2019/04/22 15:34:56 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_freelst(t_list **head)
{
	t_list *tmp;
	while(*head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp->content);
		free(tmp);
	}
}

void	run_fillit(char *f_name)
{
	t_list	*tetros;
	char	**map;

	tetros = read_file(f_name);
	solve_tetros(&map, tetros);
	ft_freelst(&tetros);
	output(map);
	free_map(map);
}
