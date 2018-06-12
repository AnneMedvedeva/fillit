/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <amedvedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:54:14 by amedvedi          #+#    #+#             */
/*   Updated: 2018/01/18 11:12:30 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfillit.h"

/*
** Finds coordinates before and after matrix transponation from
** top left position.
*/

int		find_coords_y1_x1(char **tetr)
{
	int i;
	int coord;

	coord = 0;
	i = 0;
	while (i < 4)
	{
		if (is_sharp(tetr[i]))
		{
			coord = i;
			break ;
		}
		i++;
	}
	return (coord);
}

/*
** Finds coordinates before and after matrix transponation from
** lower right position.
*/

int		find_coords_y2_x2(char **tetr)
{
	int	i;
	int coord;

	coord = 0;
	i = 3;
	while (i >= 0)
	{
		if (is_sharp(tetr[i]) == 1)
		{
			coord = i;
			break ;
		}
		i--;
	}
	return (coord);
}

/*
** Transponates matrix with interchanging iterators i and j.
*/

void	transp_matrix(char **tetr)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	while (i < 4)
	{
		j = i;
		while (j < 4)
		{
			tmp = tetr[i][j];
			tetr[i][j] = tetr[j][i];
			tetr[j][i] = tmp;
			j++;
		}
		i++;
	}
}

/*
** Trims piece to tetrimino with specified coordinates.
*/

char	**trim_data(char **data, t_point p1, t_point p2)
{
	int		i;
	int		h;
	int		w;
	char	**trimmed;

	h = p2.y - p1.y + 1;
	w = p2.x - p1.x + 1;
	if ((trimmed = ft_memalloc(sizeof(char*) * h)))
	{
		i = 0;
		while (i < h)
			trimmed[i++] = ft_strsub(data[p1.y++], p1.x, w);
		return (trimmed);
	}
	return (NULL);
}

/*
** Writes sharp position into array of ints for future usage.
*/

int		**get_coords(char **data, int h, int w)
{
	int **arr;
	int i;
	int j;
	int k;

	if (!(arr = (int**)ft_memalloc(sizeof(int*) * 4)))
		return (NULL);
	i = 0;
	k = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			if (data[i][j] == '#' && (arr[k] = (int*)malloc(sizeof(int) * 2)))
			{
				arr[k][0] = j;
				arr[k][1] = i;
				k++;
			}
			j++;
		}
		i++;
	}
	return (arr);
}
