/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchernia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 20:11:04 by kchernia          #+#    #+#             */
/*   Updated: 2017/12/01 02:41:07 by kchernia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int c, size_t n)
{
	unsigned char *p;

	p = (unsigned char*)ptr;
	while (n--)
	{
		if (*p == (unsigned char)c)
			return (p);
		else
			p++;
	}
	return (NULL);
}
