/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:02:55 by jabae             #+#    #+#             */
/*   Updated: 2022/07/15 19:43:00 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define ESC 53

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17

# define BUFFER_SIZE 2

typedef struct s_image
{
	int				x;
	int				y;
	void			*img;
}	t_image;

typedef struct s_player
{
	int		x;
	int		y;
	t_image	image;
}	t_player;

typedef struct s_map
{
	char		**blueprint; // 맵을 이중배열로
	int			x; // 가로
	int			y; // 세로
	int			item_num; // 아이템 수
	int			exit_num; // 출구 수, 최소 1개 이상 필요
	int			start_x;
	int			start_y;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	int		steps; // 걸음 수
	// int		move[4][2]; // 상하좌우 x축 y축
	t_image		wall;
	t_image		ground;
	t_image		item;
	t_image		exit;
	t_map			map;
	t_player	player;
}	t_game;

void	ft_init_game(t_game *game, int fd);
t_map	ft_parse_map(int fd);

#endif