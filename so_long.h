/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:02:55 by jabae             #+#    #+#             */
/*   Updated: 2022/07/17 22:37:02 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

# define KEYCODE_PRESS 2
# define KEYCODE_EXIT 17

# define BUFFER_SIZE 2
# define IMG_SIZE 32

// typedef struct s_image
// {
// 	int				x; // size
// 	int				y; // size
// 	void			*img;
// }	t_image;

typedef struct s_map
{
	char		**blueprint; // 맵을 이중배열로
	int			x; // 가로
	int			y; // 세로
	int			item_num; // 아이템 수
	int			exit_num; // 출구 수, 최소 1개 이상 필요
	int			player_x;
	int			player_y;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	int		steps;
	void	*wall;
	void	*empty;
	void	*item;
	void	*exit;
	void	*player;
	t_map			map;
}	t_game;

t_map	ft_parse_map(int fd);
void	ft_error(char *message);
int		ft_exit(t_game *game);
void	ft_set_image(t_game *game);
void	ft_draw_map(t_game *game);
void	ft_move_player(int key, t_game *game);

#endif