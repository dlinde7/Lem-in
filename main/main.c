#include "lem_in.h"

static int		is_empty(char *s)
{
	int n;

	n = 0;
	while (s[n] && ft_isspace(s[n]))
		n++;
	if (n == (int)ft_strlen(s) && n > 0)
		return (1);
	return (0);
}

static t_map	*map_2(t_map *nest)
{
	int n;
	int i;

	n = -1;
	nest->path = (int*)ft_memalloc(sizeof(int) * 10000);
	nest->matrix = (int**)ft_memalloc(sizeof(int*) * nest->num_rooms);
	nest->rooms = (char**)ft_memalloc(sizeof(char*) * (nest->num_rooms + 1));
	while (++n < nest->num_rooms)
	{
		nest->path[n] = -1;
		nest->rooms[n] = NULL;
		nest->matrix[n] = (int*)ft_memalloc(sizeof(int) * nest->num_rooms);
		i = -1;
		while (nest->matrix[n][++i])
			nest->matrix[n][i] = 0;
	}
	nest->path[0] = 0;
	return (nest);
}

static void		read_map(t_map *nest)
{
	char *line;

	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		if (nest->num_ants == 0)
			count_ants(nest, line);
		else if (ft_strchr(line, '-') || nest->process_index == 3)
			links(nest, line);
		else if ((nest->process_index == 1 || nest->process_index == 2) && !is_empty(line))
			rooms(nest, line);
		else
			exit_func(nest, 1, 0);
	}
	if (!nest->num_ants || !nest->links[0])
		exit_func(nest, 1, 0);
	nest = map_2(nest);
}

static t_map	*map(void)
{
	t_map *nest;

	nest = (t_map*)ft_memalloc(sizeof(t_map));
	nest->num_ants = 0;
	nest->rooms_list = ft_strnew(1);
	nest->links = ft_strnew(1);
	nest->rooms = NULL;
	nest->num_rooms = 0;
	nest->process_index = 0;
	nest->cur_room = 0;
	nest->path_indx = 0;
	nest->valid[0] = 0;
	nest->valid[1] = 0;
	nest->matrix = NULL;
	nest->path = NULL;
	return (nest);
}

int				main(void)
{
	t_map *nest;

	nest = map();
	read_map(nest);
	add_rooms(nest);
	if (!nest->valid[0] || !nest->valid[1])
		exit_func(nest, 1, 1);
	create_matrix(nest);
	if (solve(nest, 0))
		result(nest);
	else
		exit_func(nest, 1, 1);
	exit_func(nest, 0, 1);
}