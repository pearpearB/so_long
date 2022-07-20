/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 22:29:53 by jabae             #+#    #+#             */
/*   Updated: 2022/07/20 14:10:16 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_make_2d_array(int fd, t_map *map)
{
	int		read_size;
	char	*buf;
	char	*tmp;
	char	*map_frame;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	map_frame = ft_strdup("");
	if (!buf || !map_frame)
		ft_error("Memory allocation failed");
	read_size = read(fd, buf, BUFFER_SIZE);
	while (read_size >= BUFFER_SIZE)
	{
		buf[read_size] = '\0';
		tmp = map_frame;
		map_frame = ft_strjoin(tmp, buf);
		if (!map_frame)
			ft_error("Memory allocation failed");
		free(tmp);
		read_size = read(fd, buf, BUFFER_SIZE);
	}
	map->map_frame = ft_split(map_frame, '\n');
	if (!map->map_frame)
		ft_error("Memory allocation failed");
	free(buf);
	free(map_frame);
}

static void	ft_set_map(t_map *map)
{
	int	x;
	int	y;

	map->item_num = 0;
	map->exit_num = 0;
	map->player_x = 0;
	map->player_y = 0;
	x = 0;
	y = 0;
	while (map->map_frame[y])
		y++;
	x = ft_strlen(map->map_frame[0]);
	if (x < 3 || y < 3)
		ft_error("Invalid Map");
	map->x = x;
	map->y = y;
}

t_map	ft_parsing_map(int fd)
{
	t_map	map;

	ft_make_2d_array(fd, &map);
	ft_set_map(&map);
	ft_check_map(&map);
	ft_check_and_set_element(&map);
	return (map);
}
