/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchernia <kchernia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 19:47:54 by kchernia          #+#    #+#             */
/*   Updated: 2018/01/24 20:50:05 by kchernia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfillit.h"

/*
** Frees alloated map structure.
*/

void	free_map(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->size)
	{
		ft_memdel((void**)&(map->array[i]));
		i++;
	}
	ft_memdel((void**)&(map->array));
	ft_memdel((void**)&map);
}

/*
** Allocates memory for map stucture and filling it with dots.
** The size if specified for future usage.
*/

t_map	*create_map(int size)
{
	t_map	*map;
	int		i;
	int		j;

	if ((map = (t_map*)ft_memalloc(sizeof(t_map))))
	{
		map->size = size;
		if ((map->array = (char**)ft_memalloc(sizeof(char*) * size)))
		{
			i = 0;
			while (i < size)
			{
				map->array[i] = ft_strnew(size);
				j = 0;
				while (j < size)
				{
					map->array[i][j] = '.';
					j++;
				}
				i++;
			}
		}
	}
	return (map);
}

/*
** Function to print map filled with tetriminos on standart output.
*/

void	print_map(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->size)
	{
		ft_putendl(map->array[i]);
		i++;
	}
}
