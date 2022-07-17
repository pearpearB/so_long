/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:46:21 by jabae             #+#    #+#             */
/*   Updated: 2022/07/17 22:23:13 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_check_input(int argc, char *argv[]) // valid
{
	int fd;
	int file_len;

	if (argc != 2)
		ft_error("Invalid Parameter");
	file_len = ft_strlen(argv[1]);
	if (file_len < 4 || ft_strncmp(&argv[1][file_len - 4], ".ber", 4))
		ft_error("Invalid File name");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error("Invalid File");
	return (fd);
}

static int ft_key_press(int key, t_game *game)
{
	if (key == KEY_ESC)
		ft_exit(game);
	else if (key == KEY_W)
		ft_move_player(0, game);
	else if (key == KEY_A)
		ft_move_player(1, game);
	else if (key == KEY_S)
		ft_move_player(2, game);
	else if (key == KEY_D)
		ft_move_player(3, game);
	return (0);
}

static void	ft_init_game(t_game *game, int fd)
{
	game->map = ft_parse_map(fd);
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error("Mlx init");
	game->window = mlx_new_window(game->mlx, game->map.x * 32, \
		game->map.y * 32, "jabae's so_long");
	if (!game->window)
		ft_error("Mlx window");
	ft_set_image(game);
	game->steps = 0;
}

int	main(int argc, char *argv[])
{
	t_game	game;
	int			fd;

	fd = ft_check_input(argc, argv);
	ft_init_game(&game, fd);
	ft_draw_map(&game);
	mlx_hook(game.window, KEYCODE_PRESS, 0, ft_key_press, &game);
	mlx_hook(game.window, KEYCODE_EXIT, 0, ft_exit, &game); // 왜 두 개가 다른 파라미터를 받을까
	mlx_loop(game.mlx);
	return(0);
}