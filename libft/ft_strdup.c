/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchernia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:37:56 by kchernia          #+#    #+#             */
/*   Updated: 2017/12/01 03:04:35 by kchernia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	char *str2;

	str2 = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (str2)
		ft_memcpy(str2, str, ft_strlen(str) + 1);
	return (str2);
}
