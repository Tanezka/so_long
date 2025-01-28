/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_shape_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaraaga <tkaraaga@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:36:02 by tkaraaga          #+#    #+#             */
/*   Updated: 2023/10/19 18:21:59 by tkaraaga         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	check_top(char **map, int *flag)
{
	int	i;

	i = -1;
	while (ft_isprint(map[0][++i]))
	{
		if (map[0][i] != '1')
			return ;
	}
	*flag = 1;
}

void	check_left(char **map, int *flag)
{
	int	i;

	i = -1;
	while ((map[++i]))
	{
		if (map[i][0] != '1')
			return ;
	}
	*flag = 1;
}

void	check_right(char **map, int *flag)
{
	int	i;
	int	x;

	i = -1;
	x = 0;
	while (ft_isprint(map[0][x]))
	{
		x++;
		if (map[0][x] == 0)
			break ;
	}
	x--;
	while (map[++i])
	{
		if (map[i][x] != '1')
			return ;
	}
	*flag = 1;
}

void	check_bottom(char **map, int *flag)
{
	int	y;
	int	i;

	i = -1;
	y = 0;
	while (map[y] != NULL)
		y++;
	y--;
	while (ft_isprint(map[y][++i]))
	{
		if (map[y][i] != '1')
			return ;
	}
	*flag = 1;
}

int	is_rectangle(char **map)
{
	int	x;
	int	y;
	int	len;

	y = 1;
	len = 0;
	while (ft_isprint(map[0][len]))
		len++;
	while (map[y])
	{
		x = 0;
		while (ft_isprint(map[y][x]))
			x++;
		if (x != len)
			return (0);
		y++;
	}
	return (1);
}
