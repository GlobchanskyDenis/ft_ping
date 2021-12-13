/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_szttoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <bsabre-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 23:14:17 by bsabre-c          #+#    #+#             */
/*   Updated: 2021/09/06 23:06:26 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strconv.h"

char	*ft_szttoa(size_t n)
{
	int			len;
	long long	temp;
	char		*dst;

	temp = n;
	len = 1;
	temp = temp / 10;
	while (temp)
	{
		len++;
		temp = temp / 10;
	}
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	dst[len] = '\0';
	while (--len >= 0)
	{
		dst[len] = (char)(n % 10 + '0');
		n = n / 10;
	}
	return (dst);
}
