/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchernia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 23:29:04 by kchernia          #+#    #+#             */
/*   Updated: 2017/12/13 00:34:41 by kchernia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*mapped_list;
	t_list	*cur;

	if (lst && f)
	{
		mapped_list = f(lst);
		cur = mapped_list;
		while (lst->next)
		{
			if (!(cur->next = f(lst->next)))
			{
				ft_memdel((void**)&(cur->next));
				return (NULL);
			}
			lst = lst->next;
			cur = cur->next;
		}
		return (mapped_list);
	}
	return (NULL);
}
