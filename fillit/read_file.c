//
// Created by Jasper Leann on 2019-04-18.
//

#include "libft.h"
#include <fcntl.h>
#include "fillit.h"

void	*read_file(char *f_name)
{
	int fd;

	if (!(fd = open(f_name, O_RDONLY)) > 0)
		raise_error("FILE ERROR!!");
	//ft_get_next_line(fd, );
	return (0);
}