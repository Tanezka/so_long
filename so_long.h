/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaraaga <tkaraaga@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:51:03 by tkaraaga          #+#    #+#             */
/*   Updated: 2023/10/19 18:04:24 by tkaraaga         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_game
{
	char		**map;
	void		*mlx;
	void		*window;
	void		*wall;
	void		*coin;
	void		*exit;
	void		*player;
	void		*background;
	int			player_x;
	int			player_y;
	int			player_coins;
	int			coin_nb;
	int			(*fnc1)();
	int			row;
	int			collumn;
	int			movement;
	int			win;
	int			fd;
	int			flag;
}			t_game;

void	free_map(char **map);

void	find_player(char **map, int *j, int *k);

char	**ft_map_cpy(char **map);

void	path_rec(char **map, int y, int x, int array[2]);

int		path_start(char **map, int y, int x, int c);

int		path_finder(char **map, int c, t_game *game);

char	**expand_map(char **str);

char	**map_to_str(int fd);

void	check_top(char **map, int *flag);

void	check_left(char **map, int *flag);

void	check_right(char **map, int *flag);

void	check_bottom(char **map, int *flag);

int		is_rectangle(char **map);

int		check_entities(char **map);

int		check_map(char **map, t_game *game);

void	free_img(t_game *game);

void	find_player_loc(char **map, int *x, int *y);

void	check_win(t_game *game, int flag);

void	move(t_game *game, int x, int y);

int		close_game(t_game *game);

int		input(int keycode, t_game *game);

void	upload_xpm(t_game *game);

void	paint_everywhere(t_game *game);

void	put_images(t_game *game);

void	get_r_c(t_game *game);

void	ft_error(const char *str);
#endif
