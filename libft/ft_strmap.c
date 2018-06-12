/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchernia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 08:42:33 by kchernia          #+#    #+#             */
/*   Updated: 2017/12/03 11:35:09 by kchernia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*p;
	int		i;

	if (!s || !f)
		return (NULL);
	p = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (p)
	{
		i = 0;
		while (s[i] != '\0')
		{
			p[i] = f(s[i]);
			i++;
		}
		p[i] = '\0';
	}
	return (p);
}
