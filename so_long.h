/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:02:55 by jabae             #+#    #+#             */
/*   Updated: 2022/07/20 14:10:16 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./mlx/mlx.h"
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

typedef struct s_map
{
	char		**map_frame;
	int			x;
	int			y;
	int			item_num;
	int			exit_num;
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

void	ft_error(char *message);
int		ft_exit(t_game *game);
int		ft_check_input(int argc, char *argv[]);
void	ft_check_map(t_map *map);
void	ft_check_and_set_element(t_map *map);
t_map	ft_parsing_map(int fd);
void	ft_set_image(t_game *game, int size);
void	ft_draw_map(t_game *game);
void	ft_move_player(int key, t_game *game);

#endif