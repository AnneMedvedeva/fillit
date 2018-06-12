/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchernia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 09:58:58 by kchernia          #+#    #+#             */
/*   Updated: 2017/12/12 22:59:16 by kchernia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*p;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen((char *)s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	p = (char *)malloc(sizeof(char) * (j - i + 1));
	if (!p)
		return (NULL);
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	k = 0;
	while (i <= j)
	{
		p[k] = s[i];
		i++;
		k++;
	}
	p[k] = '\0';
	return (p);
}
