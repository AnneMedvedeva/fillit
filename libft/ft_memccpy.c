/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchernia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:15:07 by kchernia          #+#    #+#             */
/*   Updated: 2017/12/12 18:39:48 by kchernia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*s1;
	const char	*s2;

	s1 = (char*)dst;
	s2 = (const char*)src;
	while (n--)
	{
		*s1++ = *s2++;
		if ((unsigned char)*(s1 - 1) == (unsigned char)c)
			return (s1);
	}
	return (NULL);
}
