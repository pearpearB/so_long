/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_and_set_image.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:58:20 by jabae             #+#    #+#             */
/*   Updated: 2022/07/20 14:10:16 by jabae            ###   ########.fr       */
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
			if (game->map.map_frame[y][x] == 'P')
				ft_put_img_window(*game, game->player, x, y);
			else if (game->map.map_frame[y][x] == 'E')
				ft_put_img_window(*game, game->exit, x, y);
			else if (game->map.map_frame[y][x] == 'C')
				ft_put_img_window(*game, game->item, x, y);
			else if (game->map.map_frame[y][x] == '1')
				ft_put_img_window(*game, game->wall, x, y);
			else
				ft_put_img_window(*game, game->empty, x, y);
		}
	}
}

void	ft_set_image(t_game *game, int tmp)
{
	game->wall = mlx_xpm_file_to_image(game->mlx, \
		"./img/wall.xpm", &tmp, &tmp);
	game->empty = mlx_xpm_file_to_image(game->mlx, \
		"./img/empty.xpm", &tmp, &tmp);
	game->item = mlx_xpm_file_to_image(game->mlx, \
		"./img/item.xpm", &tmp, &tmp);
	game->exit = mlx_xpm_file_to_image(game->mlx, \
		"./img/exit.xpm", &tmp, &tmp);
	game->player = mlx_xpm_file_to_image(game->mlx, \
		"./img/player.xpm", &tmp, &tmp);
	if (!game->wall || !game->empty || !game->item
		|| !game->exit || !game->player)
		ft_error("MLX images");
}