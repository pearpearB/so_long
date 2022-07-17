/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 22:29:53 by jabae             #+#    #+#             */
/*   Updated: 2022/07/17 22:22:05 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

static t_map	ft_make_2Darray(int fd)
{
	int		read_size;
	char	*buf;
	char	*blueprint;
	t_map	map;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		ft_error("Malloc");
	blueprint = ft_strdup("");
	while (1)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		buf[read_size] = '\0';
		blueprint = ft_strjoin(blueprint, buf);
		if (read_size < BUFFER_SIZE)
			break ;
	}
	map.blueprint = ft_split(blueprint, '\n');
	free(buf);
	free(blueprint);
	return (map);
}

static void	ft_check_element(t_map *map, int x, int y)
{
	if (map->blueprint[y][x] == 'C')
		map->item_num++;
	else if (map->blueprint[y][x] == 'E')
		map->exit_num++;
	else if (map->blueprint[y][x] == 'P' && map->player_x == 0)
	{
		map->player_x = x;
		map->player_y = y;
	}
	else if (map->blueprint[y][x] != '0' && map->blueprint[y][x] != '1')
		ft_error("Incorrect array elements.");
}

static void ft_check_map(t_map *map)
{
	int i;

	i = 0;
	while (++i < map->y) // 직사각형인지 체크하기
		if((int)ft_strlen(map->blueprint[i]) != map->x)
			ft_error("Map must be rectangular.");
	i = -1;
	while (++i < map->x) // 가로
		if (map->blueprint[0][i] != '1' || map->blueprint[map->y -1][i] != '1')
			ft_error("Map must be surrounded by walls.(row)");
	i = 0;
	while (++i < map->y-1) // 세로
	{
		if (map->blueprint[i][0] != '1' || map->blueprint[i][map->x -1] != '1')
			ft_error("Map must be surrounded by walls.(col)");
	}
}

t_map	ft_parse_map(int fd)
{
	t_map	map;
	int x;
	int y;

	map = ft_make_2Darray(fd);
	y = 0;
	while(map.blueprint[y])
		y++;
	if (!y)
		ft_error("Invalid map!");
	x = ft_strlen(map.blueprint[0]);
	map.y = y;
	map.x = x;
	map.item_num = 0;
	map.exit_num = 0;
	map.player_x = 0;
	map.player_y = 0;
	ft_check_map(&map);
	while (y--)
	{
		x = map.x;
		while (x--)
			ft_check_element(&map, x, y);
	}
	if (map.item_num == 0 || map.exit_num == 0 || map.player_x == 0)
		ft_error("Map must have at least one exit, one collectible, and one starting position.");
	return (map);
}