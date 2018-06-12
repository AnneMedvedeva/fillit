/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchernia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 09:31:22 by kchernia          #+#    #+#             */
/*   Updated: 2017/12/03 11:37:13 by kchernia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			p[i] = f(i, s[i]);
			i++;
		}
		p[i] = '\0';
	}
	return (p);
}
