/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchernia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 21:57:39 by kchernia          #+#    #+#             */
/*   Updated: 2017/12/12 22:06:13 by kchernia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrchr(const void *ptr, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char*)ptr;
	while (n > 0)
	{
		if (p[n] == (unsigned char)c)
			return ((p + n));
		n--;
		if (n == 0)
		{
			if (p[n] == (unsigned char)c)
				return ((p + n));
			break ;
		}
	}
	return (NULL);
}
