/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:58:43 by jabae             #+#    #+#             */
/*   Updated: 2021/12/17 15:47:29 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1 && !set)
		return (NULL);
	if (!s1)
		return (ft_strdup(""));
	if (!set)
		return (ft_strdup(s1));
	i = 0;
	start = i;
	while (s1[i] && ft_strchr(set, s1[i]))
		start = (i++) + 1;
	i = ft_strlen(s1) - 1;
	end = i;
	while (s1[i] && ft_strchr(set, s1[i]) && i)
		end = (i--) - 1;
	if (start > end)
		return (ft_strdup(""));
	else
		return (ft_substr(s1, start, end - start + 1));
}
