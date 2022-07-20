/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:56:33 by jabae             #+#    #+#             */
/*   Updated: 2022/07/20 14:00:10 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void ft_steps_and_draw(t_game *game, int dir_y, int dir_x)
{
	printf("steps: %d\n", ++game->steps);
	game->map.blueprint[game->map.player_y][game->map.player_x] = '0';
	game->map.player_x = dir_x;
	game->map.player_y = dir_y;
	game->map.blueprint[dir_y][dir_x] = 'P';
	ft_draw_map(game);
}

void	ft_move_player(int key, t_game *game)
{
	const int	y[4] = {-1, 0, 1, 0};
	const int	x[4] = {0, -1, 0, 1};
	int			dir_y;
	int			dir_x;

	dir_y = game->map.player_y + y[key];
	dir_x = game->map.player_x + x[key];
	if (game->map.blueprint[dir_y][dir_x] == '1')
		return ;
	else if (game->map.blueprint[dir_y][dir_x] == 'E')
	{
		if (game->map.item_num == 0)
		{
			ft_steps_and_draw(game, dir_y, dir_x);
			printf("you Win!\n");
			ft_exit(game);
		}
		else
			return ;
	}
	else if (game->map.blueprint[dir_y][dir_x] == 'C')
		game->map.item_num--;
	ft_steps_and_draw(game, dir_y, dir_x);
}
