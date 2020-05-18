#include "lem_in.h"

static void	check_start_end(t_map *nest, char **s, int n)
{
	if (n)
	{
		nest->rooms[nest->num_rooms - 1] = ft_strdup(s[0]);
		(nest->valid[1])++;
		return;
	}
	nest->rooms[0] = ft_strdup(s[0]);
	(nest->valid[0])++;
}

static void	good(t_map *nest, char **line, char **s, int n)
{
	if (++(nest->valid[n]) > 1)
	{
		free_array(s, nest, 0);
		free_array(line, nest, 1);
	}
}

static void	is_valid(t_map *nest, int n, char **s)
{
	int index;

	index = room_index(nest, s[0], 0);
	if (index > 0 && n != index)
		exit_func(nest, 1, 1);
	nest->rooms[n] = ft_strdup(s[0]);
}

void		add_rooms(t_map *nest)
{
	int		n;
	int		i;
	char	**line;
	char	**s;

	n = -1;
	i = 1;
	line = ft_strsplit(nest->rooms_list, '\n');
	while (line[++n] && i < nest->num_rooms)
	{
		s = ft_strsplit(line[n], ' ');
		if (!ft_strcmp("##start", line[n]))
			good(nest, line, s, 0);
		else if (!ft_strcmp("##end", line[n]))
			good(nest, line, s, 1);
		else if (nest->valid[0] == 1 && line[n][0] != '#')
			check_start_end(nest, s, 0);
		else if (nest->valid[1] == 1 && line[n][0] != '#')
			check_start_end(nest, s, 1);
		else if (line[n][0] != '#')
			is_valid(nest, i++, s);
		free_array(s, nest, 0);
	}
	free_array(line, nest, 0);
}

int	room_index(t_map *nest, char *str, int n)
{
	int index;

	if (n) {
		index = -1;
	}else {
		index = 0;
	}
	while (nest->rooms[++index] && index < nest->num_rooms)
	{	
		if (ft_strcmp(nest->rooms[index], str) == 0)
			return (index);
	}
	return (index);
}