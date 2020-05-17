#include "lem_in.h"

void	exit_func(t_map *nest, int n, int i)
{
	int j;

	free(nest->links);
	free(nest->rooms_list);
	if (i)
	{
		free(nest->path);
		free_array(nest->rooms, nest, 0);
		j = -1;
		while (++j < nest->num_rooms)
			free(nest->matrix[j]);
		free(nest->matrix);
	}
	free(nest);
	if (n)
	{
		ft_putstr_fd("ERROR", 2);
		exit(1);
	}
	exit(0);
}

void	free_array(char **s, t_map *nest, int n)
{
	int i;

	i = 0;
	while (s[i]){
		if (s[i]) {
			free(s[i++]);
		}
	}
	free(s);
	if (n)
		exit_func(nest, 1, 1);
	s = NULL;
}

int		ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\a')
		return (1);
	return (0);
}

char	*join_str(char *s1, char *s2)
{
	char *new_s;

	new_s = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s1[0] == 0)
		return (s2);
	ft_strcat(new_s, s1);
	ft_strcat(new_s, "\n");
	ft_strcat(new_s, s2);
	ft_strdel(&s1);
	return (new_s);
}