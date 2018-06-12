/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <amedvedi@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 22:03:54 by amedvedi          #+#    #+#             */
/*   Updated: 2018/01/24 22:05:16 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfillit.h"

/*
** Function to determine if the passed char in string
** is sharp.
*/

int		is_sharp(char *str)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (str[i] == '#')
			return (1);
		i++;
	}
	return (0);
}

/*
** Counts elements in a list.
** Used to check if the passed tetriminos are not exceeding the limit
** in 26 pieces.
*/

int		ft_lstcount(t_list *list)
{
	int		i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

/*
** Calculates rounded up sqrt on a number.
*/

int		high_sqrt(int n)
{
	int		i;

	i = 2;
	while (i * i < n)
		i++;
	return (i);
}
