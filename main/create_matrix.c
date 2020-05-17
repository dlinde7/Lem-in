#include "lem_in.h"

static void	validate_link(t_map *nest, char *link)
{
	char **s;

	s = ft_strsplit(link, '-');
	if (s[2] != NULL)
		free_array(s, nest, 1);
	free_array(s, nest, 0);
}

void		create_matrix(t_map *nest)
{
	int		n;
	int		l1;
	int		l2;
	char	**s;
	char	**links;

	n = -1;
	links = ft_strsplit(nest->links, '\n');
	while (links[++n])
	{
		if (links[n][0] == '#')
			continue;
		validate_link(nest, links[n]);
		s = ft_strsplit(links[n], '-');
		if ((l1 = room_index(nest, s[0], 1)) >= nest->num_rooms ||
			(l2 = room_index(nest, s[1], 1)) >= nest->num_rooms)
		{
			free_array(s, nest, 0);
			free_array(links, nest, 1);
		}
		if (l2)
		{
			nest->matrix[l1][l2] = 1;
		}
		if (l1)
		{
			nest->matrix[l2][l1] = 1;
		}
		free_array(s, nest, 0);
	}
	free_array(links, nest, 0);
}