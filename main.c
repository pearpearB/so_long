/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:46:21 by jabae             #+#    #+#             */
/*   Updated: 2022/07/14 22:50:30 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *message)
{
	ft_putstr_fd("[Error] ", 2);
	ft_putendl_fd(message, 2);
	exit(EXIT_FAILURE);
}

static int	ft_check_input(int argc, char *argv[])
{
	int fd;
	int file_len;

	if (argc != 2)
		ft_error("Invalid Parameter");
	file_len = ft_strlen(argv[1]);
	if (file_len < 4 || ft_strcmp(&argv[1][file_len - 4], ".ber"))
		ft_error("Invalid File name");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error("Invalid File");
	return (fd);
}

int	main(int argc, char *argv[])
{
	t_game	game;
	int			fd;

	fd = ft_check_input(argc, argv);
	ft_init_game(&game, fd);

	return(0);
}