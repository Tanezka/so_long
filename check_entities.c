/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_entities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaraaga <tkaraaga@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:28:03 by tkaraaga          #+#    #+#             */
/*   Updated: 2023/10/19 15:16:04 by tkaraaga         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"
#include "mlx/mlx.h"

int	check_entities(char **map)
{
	int	x;
	int	y;
	int	array[3];

	y = 3;
	while (--y != -1)
		array[y] = 0;
	while (map[++y] != NULL)
	{
		x = -1;
		while (ft_isprint(map[y][++x]))
		{
			if (map[y][x] == 'C')
				array[0]++;
			else if (map[y][x] == 'E')
				array[1]++;
			else if (map[y][x] == 'P')
				array[2]++;
			else if (map[y][x] != '1' && map[y][x] != '0')
				return (0);
		}
	}
	if (array[2] == 1 && array[1] == 1 && array[0] > 0)
		return (array[0]);
	return (0);
}

void	get_r_c(t_game *game)
{
	int	i;
	int	k;

	i = 0;
	k = i;
	while (game->map[i] != NULL)
		i++;
	game->row = i - 1;
	while (ft_isprint(game->map[0][k]))
		k++;
	game->collumn = k;
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, 96 * (game->collumn),
			96 * (game->row + 1), "So_long");
	game->fnc1 = input;
	mlx_key_hook(game->window, game->fnc1, game);
	mlx_hook(game->window, 17, 0, close_game, game);
	upload_xpm(game);
	game->flag = 0;
}

void	check_win(t_game *game, int flag)
{
	if (flag == 1 && (game->player_coins == game->coin_nb))
		game->win = 1;
}

void	free_img(t_game *game)
{
	mlx_destroy_image(game->mlx, game->player);
	mlx_destroy_image(game->mlx, game->coin);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_image(game->mlx, game->background);
}
