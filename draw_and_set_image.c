/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_and_set_image.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:58:20 by jabae             #+#    #+#             */
/*   Updated: 2022/07/20 13:58:51 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_put_img_window(t_game game, void *img, int x, int y)
{
	mlx_put_image_to_window(game.mlx, game.window, img, \
		x * IMG_SIZE, y * IMG_SIZE);
}

void	ft_draw_map(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->map.y)
	{
		x = -1;
		while (++x < game->map.x)
		{
			if (game->map.blueprint[y][x] == 'P')
				ft_put_img_window(*game, game->player, x, y);
			else if (game->map.blueprint[y][x] == 'E')
				ft_put_img_window(*game, game->exit, x, y);
			else if (game->map.blueprint[y][x] == 'C')
				ft_put_img_window(*game, game->item, x, y);
			else if (game->map.blueprint[y][x] == '1')
				ft_put_img_window(*game, game->wall, x, y);
			else
				ft_put_img_window(*game, game->empty, x, y);
		}
	}
}

void	ft_set_image(t_game *game)
{
	void	*wall;
	void	*empty;
	void	*item;
	void	*exit;
	void	*player;
	int		tmp;

	tmp = 32;
	wall = mlx_xpm_file_to_image(game->mlx, "./images/wall.xpm", &tmp, &tmp);
	empty = mlx_xpm_file_to_image(game->mlx, "./images/empty.xpm", &tmp, &tmp);
	item = mlx_xpm_file_to_image(game->mlx, "./images/item.xpm", &tmp, &tmp);
	exit = mlx_xpm_file_to_image(game->mlx, "./images/exit.xpm", &tmp, &tmp);
	player = mlx_xpm_file_to_image(game->mlx, "./images/player.xpm", &tmp, &tmp);
	if (!wall || !empty || !item || !exit || !player)
		ft_error("MLX images");
	game->wall = wall;
	game->empty = empty;
	game->item = item;
	game->exit = exit;
	game->player = player;
}