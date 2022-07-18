/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 22:29:53 by jabae             #+#    #+#             */
/*   Updated: 2022/07/18 01:44:12 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_map	ft_make_2Darray(int fd)
{
	int		read_size;
	char	*buf;
	char	*blueprint;
	t_map	map;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		ft_error("Memory allocation failed");
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

static void ft_set_map(t_map *map)
{
	int x;
	int y;

	map->item_num = 0;
	map->exit_num = 0;
	map->player_x = 0;
	map->player_y = 0;
	x = 0;
	y = 0;
	while(map->blueprint[y])
		y++;
	if (!y)
		ft_error("Map is Empty");
	x = ft_strlen(map->blueprint[0]);
	map->x = x;
	map->y = y;
}

t_map	ft_parsing_map(int fd)
{
	t_map	map;

	map = ft_make_2Darray(fd);
	ft_set_map(&map);
	ft_check_map(&map);
	ft_check_and_set_element(&map);
	return (map);
}
