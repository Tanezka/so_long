/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaraaga <tkaraaga@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:52:10 by tkaraaga          #+#    #+#             */
/*   Updated: 2023/10/19 15:10:55 by tkaraaga         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"
#include "libft/libft.h"

void	upload_xpm(t_game *game)
{
	int	x;
	int	y;

	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &x, &y);
	game->coin = mlx_xpm_file_to_image(game->mlx, "textures/coin.xpm", &x, &y);
	game->player = mlx_xpm_file_to_image(game->mlx,
			"textures/player.xpm", &x, &y);
	game->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &x, &y);
	game->background = mlx_xpm_file_to_image(game->mlx,
			"textures/back.xpm", &x, &y);
	paint_everywhere(game);
	put_images(game);
	mlx_loop(game->mlx);
}

void	paint_everywhere(t_game *game)
{
	int	i;
	int	k;

	k = -1;
	while (++k <= game->row)
	{
		i = -1;
		while (++i < game->collumn)
		{
			mlx_put_image_to_window(game->mlx, game->window,
				game->background, 96 * i, 96 * k);
		}
	}
	ft_printf("\rMove count: %d", (game->movement));
}

void	put_images(t_game *game)
{
	int	array[2];

	array[0] = -1;
	while (++array[0] <= game->row)
	{
		array[1] = -1;
		while (++array[1] < game->collumn)
		{
			if (game->map[array[0]][array[1]] == '1')
				mlx_put_image_to_window(game->mlx,
					game->window, game->wall, 96 * array[1], 96 * array[0]);
			else if ((game->map)[array[0]][array[1]] == '0')
				mlx_put_image_to_window(game->mlx, game->window,
					game->background, 96 * array[1], 96 * array[0]);
			else if ((game->map)[array[0]][array[1]] == 'C')
				mlx_put_image_to_window(game->mlx, game->window,
					game->coin, 96 * array[1], 96 * array[0]);
			else if ((game->map)[array[0]][array[1]] == 'E')
				mlx_put_image_to_window(game->mlx, game->window,
					game->exit, 96 * array[1], 96 * array[0]);
			else if ((game->map)[array[0]][array[1]] == 'P')
				mlx_put_image_to_window(game->mlx, game->window,
					game->player, 96 * array[1], 96 * array[0]);
		}
	}
}
