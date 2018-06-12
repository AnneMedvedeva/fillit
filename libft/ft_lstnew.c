/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchernia <kchernia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 22:41:29 by kchernia          #+#    #+#             */
/*   Updated: 2018/01/25 17:01:43 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*item;

	if ((item = (t_list*)malloc(sizeof(t_list))))
	{
		if (content)
		{
			if ((item->content = malloc(content_size)))
				ft_memmove(item->content, content, content_size);
			else
			{
				ft_memdel((void**)&item);
				return (NULL);
			}
		}
		item->content = content ? item->content : NULL;
		item->content_size = content ? content_size : 0;
		item->next = NULL;
		return (item);
	}
	return (NULL);
}
