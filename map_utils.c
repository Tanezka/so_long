/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaraaga <tkaraaga@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:38:26 by tkaraaga          #+#    #+#             */
/*   Updated: 2023/10/19 14:45:44 by tkaraaga         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"
#include <stdlib.h>

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	**expand_map(char **str)
{
	char		**pholder;
	int			i;

	i = 0;
	while (str[i])
		i++;
	pholder = (char **)malloc((ft_strlen(str[0]) * (i + 300)) * sizeof(char *));
	if (pholder == NULL)
	{
		ft_printf("Error\nMalloc error\n");
		free_map(str);
		return (NULL);
	}
	i = -1;
	while (str[++i] != NULL)
	{
		pholder[i] = ft_strdup(str[i]);
		if (pholder[i] == NULL)
		{
			free_map(str);
			return (NULL);
		}
	}
	free_map(str);
	return (pholder);
}

char	**map_to_str(int fd)
{
	char	**map;
	char	*line;
	int		i;

	line = get_next_line(fd);
	if (line == NULL)
		return (NULL);
	map = (char **)malloc(ft_strlen(line) * 1000 * sizeof(char *));
	if (map == NULL)
	{
		ft_printf("Error\nMalloc error\n");
		close(fd);
		exit(0);
	}
	i = 0;
	while (line && map != NULL)
	{
		map[i] = line;
		map = expand_map(map);
		i++;
		line = get_next_line(fd);
	}
	return (map);
}

int	check_map(char **map, t_game *game)
{
	int	top_flag;
	int	left_flag;
	int	right_flag;
	int	bottom_flag;

	top_flag = 0;
	left_flag = 0;
	right_flag = 0;
	bottom_flag = 0;
	check_top(map, &top_flag);
	check_left(map, &left_flag);
	check_right(map, &right_flag);
	check_bottom(map, &bottom_flag);
	if (top_flag == 1 && left_flag == 1 && right_flag == 1
		&& bottom_flag == 1 && is_rectangle(map)
		&& path_finder(map, check_entities(map), game))
		return (1);
	else
		return (0);
}
