/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:00:09 by jabae             #+#    #+#             */
/*   Updated: 2021/12/13 11:21:23 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*dest;
	size_t			i;

	dest = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		dest[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
