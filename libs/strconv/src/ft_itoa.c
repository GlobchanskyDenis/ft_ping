/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <bsabre-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 23:02:05 by bsabre-c          #+#    #+#             */
/*   Updated: 2021/09/06 23:02:24 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strconv.h"

static int	ft_itoa_countRanks(int src)
{
	int	rank;

	rank = 1;
	src = src / 10;
	while (src)
	{
		rank++;
		src = src / 10;
	}
	return (rank);
}

char	*ft_itoa(int n)
{
	char			*dst;
	int				ranks;
	int				sign;
	unsigned int	temp;

	ranks = ft_itoa_countRanks(n);
	sign = 0;
	if (n < 0)
		sign = 1;
	if (n < 0)
		temp = (unsigned int)(-n);
	else
		temp = (unsigned int)n;
	dst = (char *)malloc(ranks + sign + 1);
	if (!(dst))
		return (NULL);
	dst[ranks + sign] = '\0';
	while (--ranks > -1)
	{
		dst[ranks + sign] = (char)(temp % 10 + '0');
		temp = temp / 10;
	}
	if (sign)
		dst[0] = '-';
	return (dst);
}
