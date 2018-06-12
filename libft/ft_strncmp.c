/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchernia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:35:14 by kchernia          #+#    #+#             */
/*   Updated: 2017/12/13 01:23:08 by kchernia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	int				i;

	p1 = (unsigned char*)s1;
	p2 = (unsigned char*)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (p1[i] == p2[i] && p1[i] != 0 && --n > 0)
		i++;
	return (p1[i] - p2[i]);
}
