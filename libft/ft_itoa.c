/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:57:17 by jabae             #+#    #+#             */
/*   Updated: 2021/12/14 11:25:11 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_n_len(int n)
{
	size_t	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
		count++;
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		n_len;
	long long	num;

	n_len = ft_n_len(n);
	str = (char *)malloc(sizeof(char) * n_len + 1);
	num = (long long)n;
	if (!str)
		return (NULL);
	if (num == 0)
		str[0] = '0';
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	str[n_len] = '\0';
	while (num)
	{
		str[n_len - 1] = num % 10 + 48;
		num /= 10;
		n_len--;
	}
	return (str);
}
