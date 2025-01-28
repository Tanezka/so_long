/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaraaga <tkaraaga@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:25:10 by tkaraaga          #+#    #+#             */
/*   Updated: 2023/10/19 14:27:33 by tkaraaga         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <fcntl.h>
#include "libft/libft.h"
#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	t_game	game;

	if (argc != 2 || ft_strncmp(argv[1] + 4, "/.ber", 5) == 0
		|| ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), ".ber", 4) != 0)
		ft_error("Sakıncalı argüman yada argüman yok");
	game.fd = open(argv[1], O_RDONLY);
	if (game.fd == -1)
		ft_error("Sakıncalı fd");
	map = map_to_str(game.fd);
	if (map == NULL || check_map(map, &game) != 1)
	{
		ft_printf("Error\nMap is invalid.\n");
		if (map != NULL)
			free_map(map);
		close(game.fd);
		return (0);
	}
	game.map = map;
	get_r_c(&game);
}
