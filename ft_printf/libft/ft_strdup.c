/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:12:52 by mumutlu           #+#    #+#             */
/*   Updated: 2023/04/28 17:12:53 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*ptr;

	len = ft_strlen(s1) + 1;
	ptr = (char *) malloc(sizeof(char) * len);
	if (!ptr)
		return (NULL);
	if (s1 == 0)
		return (0);
	ptr = ft_memcpy(ptr, s1, len);
	return (ptr);
}
