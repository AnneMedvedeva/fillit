/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchernia <kchernia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 18:08:48 by kchernia          #+#    #+#             */
/*   Updated: 2018/01/25 18:17:39 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char*)malloc(size);
	if (ptr)
	{
		i = 0;
		while (i < size)
			ptr[i++] = 0;
	}
	return (ptr);
}
