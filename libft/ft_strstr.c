/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchernia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 20:12:30 by kchernia          #+#    #+#             */
/*   Updated: 2017/12/12 22:40:36 by kchernia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*p;
	size_t	len;

	p = NULL;
	if ((len = ft_strlen(needle)) == 0)
		return ((char*)haystack);
	p = (char*)haystack;
	while ((p = ft_strchr(p, *needle)))
	{
		if (ft_strncmp(p, needle, len) == 0)
			return (p);
		p++;
	}
	return (NULL);
}
