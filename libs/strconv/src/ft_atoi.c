/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <bsabre-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 22:58:05 by bsabre-c          #+#    #+#             */
/*   Updated: 2021/09/12 14:57:55 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	atoi_helper(char const *s, int *sign)
{
	int	i;

	i = 0;
	*sign = 1;
	while (s[i] == ' ' || s[i] == '\f' || s[i] == '\n' || s[i] == '\r'
		|| s[i] == '\t' || s[i] == '\v')
		i++;
	if (s[i] == '-')
		*sign = -1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] == '0')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int				sign;
	long long		num;
	int				i;
	int				size;

	num = 0;
	size = 0;
	i = atoi_helper(str, &sign);
	while (str[i] >= '0' && str[i] <= '9')
	{
		size++;
		num = num * 10 + (str[i] - '0');
		if ((num < 0 || size > 19) && sign == 1)
			return (-1);
		if ((num < 0 || size > 19) && sign == -1)
			return (0);
		i++;
	}
	return ((int)(num * sign));
}
