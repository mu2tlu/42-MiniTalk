/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:10:55 by mumutlu           #+#    #+#             */
/*   Updated: 2023/04/28 17:10:56 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*root;

	i = 0;
	if (lst == NULL)
		return (i);
	root = lst;
	while (root != NULL)
	{
		root = root->next;
		i++;
	}
	return (i);
}
