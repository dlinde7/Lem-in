#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/libft.h"
# include <limits.h>
# include <stdio.h>

typedef struct	s_map
{
	int			process_index;
	int			num_ants;
	char		*rooms_list;
	int			num_rooms;
	char		*links;
	char		**rooms;
	int			valid[2];
	int			**matrix;
	int			*path;
	int			cur_room;
	int			path_indx;
}				t_map;

int				ft_isspace(char c);
void			count_ants(t_map *nest, char *line);
void			rooms(t_map *nest, char *line);
void			links(t_map *nest, char *line);
void			add_rooms(t_map *nest);
void			create_matrix(t_map *nest);
int				solve(t_map *nest, int n);
char			*join_str(char *s1, char *s2);
void			free_array(char **s, t_map *nest, int n);
int				room_index(t_map *nest, char *str, int n);
void			result(t_map *nest);
void			exit_func(t_map *nest, int n, int i);
#endif