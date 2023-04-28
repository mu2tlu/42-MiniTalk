/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:14:11 by mumutlu           #+#    #+#             */
/*   Updated: 2023/04/28 17:14:12 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		index;
	char	*ptr;

	index = 0;
	ptr = 0;
	while (s[index] != '\0')
	{
		if (s[index] == (char)c)
			ptr = (char *)(s + index);
		index++;
	}
	if (s[index] == (char)c)
		return ((char *) s + index);
	return (ptr);
}
