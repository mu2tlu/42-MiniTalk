/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:08:13 by mumutlu           #+#    #+#             */
/*   Updated: 2023/04/28 17:08:14 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				number;
	int				sign;
	unsigned int	i;

	sign = 1;
	i = 0;
	number = 0;
	while ((str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		&& str[i] != '\0')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		number *= 10;
		number += str[i] - '0';
		i++;
	}
	if (sign < 0)
		return (number *= -1);
	return (number);
}
