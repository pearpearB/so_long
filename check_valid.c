/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 00:23:58 by jabae             #+#    #+#             */
/*   Updated: 2022/07/20 14:13:51 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_input(int argc, char *argv[])
{
	int fd;
	int file_len;

	if (argc != 2)
		ft_error("Invalid Parameters.");
	file_len = ft_strlen(argv[1]);
	if (file_len < 5 || ft_strncmp(&argv[1][file_len - 4], ".ber", 4))
		ft_error("Invalid File name.");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error("Failed to open map file.");
	return (fd);
}

void ft_check_map(t_map *map)
{
	int i;

	i = 0;
	while (++i < map->y)
		if((int)ft_strlen(map->map_frame[i]) != map->x)
			ft_error("Map must be rectangular.");
	i = -1;
	while (++i < map->x) 
		if (map->map_frame[0][i] != '1' || map->map_frame[map->y - 1][i] != '1')
			ft_error("Map must be surrounded by walls.");
	i = 0;
	while (++i < map->y-1)
	{
		if (map->map_frame[i][0] != '1' || map->map_frame[i][map->x - 1] != '1')
			ft_error("Map must be surrounded by walls.");
	}
}

void ft_check_and_set_element(t_map *map)
{
	int x;
	int y;
	
	y = map->y;
	while (y--)
	{
		x = map->x;
		while (x--)
		{
			if (map->map_frame[y][x] == 'C')
				map->item_num++;
			else if (map->map_frame[y][x] == 'E')
				map->exit_num++;
			else if (map->map_frame[y][x] == 'P' && map->player_x == 0)
			{
				map->player_x = x;
				map->player_y = y;
			}
			else if (map->map_frame[y][x] != '0' && map->map_frame[y][x] != '1')
				ft_error("Map has invalid characters");
		}
	}
	if (map->item_num == 0 || map->exit_num == 0 || map->player_x == 0)
		ft_error("Map must have at least one exit, one collectible, and one starting position.");
}