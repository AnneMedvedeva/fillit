/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <amedvedi@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 20:33:37 by amedvedi          #+#    #+#             */
/*   Updated: 2018/01/24 21:16:23 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfillit.h"

/*
** Sets a tetrimino with the specified character.
*/

void	set_tetr(t_tetr *t, t_map *map, t_point p, char c)
{
	int		i;

	i = -1;
	while (++i < 4)
	{
		map->array[p.y + (t->coords)[i].y][p.x + (t->coords)[i].x] = c;
	}
}

/*
** Places a tetrimino on map at top left possible position.
** Used to check if place is available.
*/

int		place_tetr(t_tetr *t, t_map *map, t_point p)
{
	int		i;

	i = -1;
	while (++i < 4)
		if (map->array[p.y + (t->coords)[i].y][p.x + (t->coords)[i].x] != '.')
			return (0);
	set_tetr(t, map, p, t->letter);
	return (1);
}

/*
** Used backtracking algorithm to implement map filling.
** If placement is done it tries to recursively place another tetrimino.
** If failed the tetriminos are changed to dots.
*/

int		solve(t_map *map, t_list *list)
{
	t_tetr		*t;
	t_point		point;

	if (list == NULL || map == NULL)
		return (1);
	t = (t_tetr*)(list->content);
	point.x = -1;
	point.y = -1;
	while ((point.x = -1) && ++(point.y) < map->size - t->height + 1)
		while (++(point.x) < map->size - t->width + 1)
			if (place_tetr(t, map, point))
			{
				if (solve(map, list->next))
					return (1);
				else
					set_tetr(t, map, point, '.');
			}
	return (0);
}
