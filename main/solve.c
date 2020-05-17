#include "lem_in.h"

static int	is_last_room(t_map *nest, int n)
{
	if (nest->matrix[n][nest->num_rooms - 1])
	{
		nest->path[++(nest->path_indx)] = n;
		nest->path[++(nest->path_indx)] = nest->num_rooms - 1;
		return (1);
	}
	return (0);
}

static void	erase_element(t_map *nest, int n, int i)
{
	nest->matrix[nest->cur_room][n] = 0;
	nest->matrix[n][nest->cur_room] = 0;
	if (i)
	{
		nest->path[nest->path_indx] = -1;
		nest->path_indx--;
	}
}

static int	find_door(t_map *nest, int n, int i)
{
	while (i < nest->num_rooms)
	{
		if (nest->matrix[n][++i] == 1){
			return (i);
		}
	}
	return (0);
}

static int	is_in_path(t_map *nest, int n)
{
	int i;

	i = -1;
	while (nest->path[++i] != -1)
	{
		if (nest->path[i] == n)
			return (1);
	}
	return (0);
}

int			solve(t_map *nest, int n)
{
	if (nest->matrix[0][nest->num_rooms - 1])
	{
		nest->path[++(nest->path_indx)] = nest->num_rooms - 1;
		return (1);
	}
	while ((n = find_door(nest, nest->cur_room, n)))
	{
		if (is_last_room(nest, n))
			return (1);
		else if (is_in_path(nest, n))
			erase_element(nest, n, 0);
	}
	if ((nest->cur_room = find_door(nest, nest->cur_room, 0)) == 0)
	{
		if (nest->path_indx == 0 || nest->cur_room == 0){
			return (0);
		}
		nest->cur_room = nest->path[nest->path_indx - 1];
		erase_element(nest, nest->path[nest->path_indx], 1);
		if (solve(nest, 0))
			return (1);
	}
	nest->path[++(nest->path_indx)] = nest->cur_room;
	if (solve(nest, 0))
		return (1);
	return (0);
}