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
/*


int main()
{
//	char test = charify(4, 0);
//	unsigned char x;
//	unsigned char y;
//	uncharify(&x, &y, test);
	char figa1[4] = {charify(2,0),charify(1,0),charify(0,0),charify(0,1)};
	char figa2[4] = {charify(1,0),charify(2,0),charify(3,0),charify(0,0)};//PALKA
	char figa3[4] = {charify(0,0),charify(1,0),charify(0,1),charify(1,1)};//SQUARE
	char figa4[4] = {charify(0,0),charify(0,1),charify(0,2),charify(1,2)};
	char figa5[4] = {charify(1,2),charify(1,1),charify(1,0),charify(0,0)};
	char figa6[4] = {charify(0,0),charify(0,1),charify(0,2),charify(1,2)};
	char **map = NULL;


	t_list *lst;
	for (int i = 0; i < 5; i++)
	{
		ft_lstadd(&lst, ft_lstnew(figa4, 5));
		ft_lstadd(&lst, ft_lstnew(figa5, 5));
	}
	ft_lstadd(&figures, fig2);
	ft_lstadd(&figures, ft_lstnew(figa3, 5));
	ft_lstadd(&figures, ft_lstnew(figa3, 5));
	ft_lstadd(&figures, ft_lstnew(figa3, 5));
	ft_lstadd(&figures, ft_lstnew(figa4, 5));
	solve_tetros(&map, lst);
	print_map(map);
	return 0;
}
*/