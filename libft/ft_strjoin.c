/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchernia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 09:51:03 by kchernia          #+#    #+#             */
/*   Updated: 2017/12/13 03:35:33 by kchernia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;

	if (s1 && s2)
	{
		new = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (new)
		{
			ft_strncpy(new, s1, ft_strlen(s1));
			ft_strncpy((new + ft_strlen(s1)), s2, ft_strlen(s2));
			return (new);
		}
	}
	return (NULL);
}
