#include "lem_in.h"

static void	print_ant(int ant, char *room)
{
	ft_putchar('L');
	ft_putnbr(ant);
	ft_putchar('-');
	ft_putstr(room);
	ft_putchar(' ');
}

static void	print_result(t_map *nest, int n)
{
	int ants;

	if (n == (nest->path_indx + nest->num_ants + 1))
		return;
	ants = nest->num_ants + 1;
	while (--ants > 0)
	{
		if (n - ants > 0 && (n - ants) <= nest->path_indx)
			print_ant(ants, nest->rooms[nest->path[n - ants]]);
	}
	if (!((n + 1) == (nest->path_indx + nest->num_ants + 1)))
	{
		ft_putchar('\n');
	}
	print_result(nest, ++n);
}

void		result(t_map *nest)
{
	ft_putendl(ft_itoa(nest->num_ants));
	ft_putendl(nest->rooms_list);
	ft_putendl(nest->links);
	ft_putstr("\n");
	print_result(nest, 2);
}