#include "libft.h"
#include "fillit.h"
#include <stdio.h>
int main(int argc, char **argv)
{
	if (argc == 2)
		run_fillit(argv[1]);
	else
		raise_error("Wrong number of arguments!!!");
	return (0);

}