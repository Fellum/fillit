/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:21:01 by mdebbi            #+#    #+#             */
/*   Updated: 2019/04/22 16:22:00 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
		run_fillit(argv[1]);
	else
		raise_error(USAGE);
	return (0);
}
