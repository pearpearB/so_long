/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:58:20 by jabae             #+#    #+#             */
/*   Updated: 2022/07/17 22:43:28 by jabae            ###   ########.fr       */
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
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.y)
	{
		j = -1;
		while (++j < game->map.x)
		{
			if (game->map.blueprint[i][j] == 'P')
				ft_put_img_window(*game, game->player, j, i);
			else if (game->map.blueprint[i][j] == 'E')
				ft_put_img_window(*game, game->exit, j, i);
			else if (game->map.blueprint[i][j] == 'C')
				ft_put_img_window(*game, game->item, j, i);
			else if (game->map.blueprint[i][j] == '1')
				ft_put_img_window(*game, game->wall, j, i);
			else
				ft_put_img_window(*game, game->empty, j, i);
		}
	}
}