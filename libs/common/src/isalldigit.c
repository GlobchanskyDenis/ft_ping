/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalldigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <bsabre-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 22:54:25 by bsabre-c          #+#    #+#             */
/*   Updated: 2021/09/06 22:54:26 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	isalldigit(char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}