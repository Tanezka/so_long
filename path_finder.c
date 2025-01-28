/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaraaga <tkaraaga@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:46:18 by tkaraaga          #+#    #+#             */
/*   Updated: 2023/10/19 18:25:07 by tkaraaga         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

void	find_player(char **map, int *j, int *k)
{
	int	x;
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				*j = y;
				*k = x;
				return ;
			}
			x++;
		}
		y++;
	}
}

char	**ft_map_cpy(char **map)
{
	char	**map_cpy;
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (map[y] != NULL)
		y++;
	while (ft_isprint(map[0][x]))
		x++;
	map_cpy = malloc((x * y));
	if (map_cpy == NULL)
		return (NULL);
	y = -1;
	while (map[++y] != NULL)
	{
		map_cpy[y] = ft_strdup(map[y]);
		if (map_cpy[y] == NULL)
			return (NULL);
	}
	map_cpy[y] = NULL;
	return (map_cpy);
}

void	path_rec(char **map, int y, int x, int array[2])
{
	if (map[y][x] == 'C')
		array[0]++;
	else if (map[y][x] == 'E')
		array[1]++;
	map[y][x] = '1';
	if (map[y - 1][x] != '1')
		path_rec(map, y - 1, x, array);
	if (map[y][x + 1] != '1')
		path_rec(map, y, x + 1, array);
	if (map[y + 1][x] != '1')
		path_rec(map, y + 1, x, array);
	if (map[y][x - 1] != '1')
		path_rec(map, y, x - 1, array);
}

int	path_start(char **map, int y, int x, int c)
{
	int	array[2];
	int	i;

	i = -1;
	array[0] = 0;
	array[1] = 0;
	path_rec(map, y, x, array);
	free_map(map);
	if (array[0] == c && array[1] == 1)
		return (1);
	return (0);
}

int	path_finder(char **map, int c, t_game *game)
{
	int		x;
	int		y;
	char	**map_cpy;

	if (c == 0)
		return (0);
	x = 0;
	y = x;
	game->coin_nb = c;
	game->player_coins = 0;
	game->win = 0;
	find_player(map, &y, &x);
	map_cpy = ft_map_cpy(map);
	if (map_cpy == NULL)
	{
		ft_printf("Error\nMalloc error\n");
		return (0);
	}
	return (path_start(map_cpy, y, x, c));
}
