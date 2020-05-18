#include "lem_in.h"

void	count_ants(t_map *nest, char *line)
{
	int		n;
	char	*s;

	n = 0;
	nest->process_index = 1;
	if (line[0] == '#')
		return;
	s = ft_strtrim(line);
	if ((nest->num_ants = ft_atoi(s)) <= 0)
		exit_func(nest, 1, 0);
	while (s[n] != '\n' && s[n] != 0)
	{
		if (!ft_isdigit(s[n++]))
			exit_func(nest, 1, 0);
	}
}

static void	is_number(char **s, t_map *nest, char *str)
{
	int n;

	n = 0;
	if (str[0] == '-' || ft_isdigit(str[0]))
	{
		while (str[++n])
		{
			if (!ft_isdigit(str[n]))
				free_array(s, nest, 1);
		}
	}
	else
		free_array(s, nest, 1);
}

static void	val_details(t_map *nest, char *line)
{
	char **s;

	s = ft_strsplit(line, ' ');
	if (s[0][0] == 'L' || s[3] != NULL)
		free_array(s, nest, 1);
	is_number(s, nest, s[1]);
	is_number(s, nest, s[2]);
	free_array(s, nest, 0);
}

void		rooms(t_map *nest, char *line)
{
	nest->process_index = 2;
	nest->rooms_list = join_str(nest->rooms_list, line);
	if (line[0] == '#')
		return;
	val_details(nest, line);
	nest->num_rooms++;
}

void	links(t_map *nest, char *line)
{
	if (nest->process_index == 2)
		nest->process_index = 3;
	if (nest->process_index != 3)
		exit_func(nest, 1, 0);
	nest->links = join_str(nest->links, line);
}