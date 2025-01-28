/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaraaga <tkaraaga@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:33:13 by tkaraaga          #+#    #+#             */
/*   Updated: 2023/10/19 15:18:23 by tkaraaga         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"
#include "libft/libft.h"
#include <fcntl.h>

int	input(int keycode, t_game *game)
{
	find_player_loc(game->map, &(game->player_x), &(game->player_y));
	if (keycode == 13)
		move(game, game->player_x, (game->player_y) - 1);
	else if (keycode == 0)
		move(game, (game->player_x) - 1, game->player_y);
	else if (keycode == 2)
		move(game, (game->player_x) + 1, game->player_y);
	else if (keycode == 1)
		move(game, game->player_x, (game->player_y) + 1);
	check_win(game, game->flag);
	if (keycode == 65307 || keycode == 12 || (game->win == 1))
		close_game(game);
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
		ft_printf("\rMove count: %d", (game->movement));
	mlx_do_sync(game->mlx);
	return (0);
}

void	move(t_game *game, int x, int y)
{
	if ((game->map)[y][x] != '1')
	{
		if (game->flag != 1)
		{
			(game->map)[game->player_y][game->player_x] = '0';
			put_images(game);
		}
		else
		{
			(game->map)[game->player_y][game->player_x] = 'E';
			mlx_put_image_to_window(game->mlx, game->window, game->background,
				game->player_x * 96, game->player_y * 96);
			mlx_put_image_to_window(game->mlx, game->window, game->exit,
				game->player_x * 96, game->player_y * 96);
			game->flag = 0;
		}
		if ((game->map)[y][x] == 'C')
			(game->player_coins)++;
		else if ((game->map)[y][x] == 'E')
			game->flag = 1;
		(game->map)[y][x] = 'P';
		mlx_put_image_to_window(game->mlx, game->window,
			game->player, x * 96, y * 96);
		++game->movement;
	}
}

int	close_game(t_game *game)
{
	int	i;

	i = -1;
	mlx_destroy_window(game->mlx, game->window);
	free_img(game);
	free_map(game->map);
	close(game->fd);
	exit(0);
}

void	find_player_loc(char **map, int *x, int *y)
{
	*y = 0;
	while (map[*y])
	{
		*x = 0;
		while (map[*y][*x] != 0)
		{
			if (map[*y][*x] == 'P')
				return ;
			(*x)++;
		}
		(*y)++;
	}
}
