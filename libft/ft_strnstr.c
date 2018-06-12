/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchernia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 04:46:48 by kchernia          #+#    #+#             */
/*   Updated: 2017/12/13 01:12:32 by kchernia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	char	*p;
	size_t	len;

	if ((len = ft_strlen(needle)) == 0)
		return ((char*)haystack);
	p = (char*)haystack;
	while ((p = ft_strchr(p, *needle)))
	{
		if ((unsigned long)(p - haystack + len) > n)
			return (NULL);
		if (ft_strncmp(p, needle, len) == 0)
			return (p);
		p++;
	}
	return (NULL);
}
