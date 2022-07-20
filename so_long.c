/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:46:21 by jabae             #+#    #+#             */
/*   Updated: 2022/07/20 14:01:55 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_exit(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	exit (EXIT_SUCCESS);
}

void	ft_error(char *message)
{
	printf("Error\n");
	printf("%s", message);
	exit(EXIT_FAILURE);
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
	game->map = ft_parsing_map(fd);
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error("Mlx init");
	game->window = mlx_new_window(game->mlx, game->map.x * 32, \
		game->map.y * 32, "jabae's so_long");
	if (!game->window)
		ft_error("Mlx window");
	ft_set_image(game, 32);
	game->steps = 0;
}

int	main(int argc, char *argv[])
{
	t_game	game;
	int		fd;

	fd = ft_check_input(argc, argv);
	ft_init_game(&game, fd);
	ft_draw_map(&game);
	mlx_hook(game.window, KEYCODE_PRESS, 0, ft_key_press, &game);
	mlx_hook(game.window, KEYCODE_EXIT, 0, ft_exit, &game);
	mlx_loop(game.mlx);
	return (0);
}