/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 19:33:55 by jabae             #+#    #+#             */
/*   Updated: 2021/12/31 18:15:52 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst_tmp;
	const unsigned char	*src_tmp;
	size_t				i;

	if (!dst && !src)
		return (dst);
	dst_tmp = (unsigned char *)dst;
	src_tmp = (const unsigned char *)src;
	if (dst_tmp > src_tmp)
	{
		i = len;
		while (i > 0)
		{
			dst_tmp[i - 1] = src_tmp[i - 1];
			i--;
		}
		return (dst);
	}
	return (ft_memcpy(dst, src, len));
}
