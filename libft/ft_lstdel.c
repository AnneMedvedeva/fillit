/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchernia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 23:29:59 by kchernia          #+#    #+#             */
/*   Updated: 2017/12/13 01:52:58 by kchernia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*temp;

	if (*alst && del)
	{
		while (*alst)
		{
			del((*alst)->content, (*alst)->content_size);
			temp = (*alst)->next;
			ft_memdel((void**)alst);
			*alst = temp;
		}
	}
}
