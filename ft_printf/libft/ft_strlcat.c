/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:13:16 by mumutlu           #+#    #+#             */
/*   Updated: 2023/04/28 17:13:17 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	sum;
	size_t	dsize;
	int		i;
	int		k;

	dsize = size;
	i = 0;
	k = 0;
	sum = ft_strlen(dst) + ft_strlen(src);
	while (dst[i] != '\0' && size > 0)
	{
		i++;
		size--;
	}
	if (size == 0)
		return (ft_strlen(src) + dsize);
	while (src[k] != '\0' && size > 1)
	{
		dst[i] = src[k];
		i++;
		k++;
		size--;
	}
	dst[i] = '\0';
	return (sum);
}
