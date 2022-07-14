/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 22:29:53 by jabae             #+#    #+#             */
/*   Updated: 2022/07/14 23:09:37 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_map	ft_make_2Darray(int fd)
{
	int		read_size;
	char	*buf;
	char	*bin;
	t_map	map;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		ft_error("Malloc");
	bin = ft_strdup("");
	// read_size = read(fd, buf, BUFFER_SIZE);
	// while(read_size < BUFFER_SIZE)
	// {
	// 	buf[read_size] = '\0';
	// 	bin = ft_strjoin(bin, buf);
	// 	read_size = read(fd, buf, BUFFER_SIZE);
	// }
	while (1)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		buf[read_size] = '\0';
		bin = ft_strjoin(bin, buf);
		if (read_size < BUFFER_SIZE)
			break ;
	}
	map->game = ft_split(bin, '\n');
	free(buf);
	free(bin);
	return (map);
}

static t_map	ft_set_map(int fd)
{
	t_map	map;

	map = ft_parse_map(fd);
	ft_map_init(&map);
	ft_check_valid_map(&map);
	return (map);
}

void	ft_init_game(t_game *game, int fd)
{
	game->map = ft_set_map(fd);
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error("Mlx init");
	game->window = mlx_new_window(game->mlx, game->map.col * 32, \
		game->map.row * 32, "jabae's so_long");
	if (!game->window)
		ft_error("Mlx window");
	ft_init_move(game);
	ft_set_images(game);
	ft_set_player(game);
}