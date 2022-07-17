/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 21:36:17 by jabae             #+#    #+#             */
/*   Updated: 2022/07/17 22:44:38 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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