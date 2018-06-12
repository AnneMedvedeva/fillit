/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchernia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 01:34:41 by kchernia          #+#    #+#             */
/*   Updated: 2017/12/05 21:25:55 by kchernia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	size_t	len;
	char	*s;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_intlen(n) + 1;
	s = (char*)malloc(sizeof(char) * len);
	if (!s)
		return (NULL);
	if (n == 0)
		s[0] = '0';
	if (n < 0)
	{
		s[0] = '-';
		n = -n;
	}
	s[len - 1] = '\0';
	while (n)
	{
		len--;
		s[len - 1] = (n % 10) + '0';
		n /= 10;
	}
	return (s);
}
