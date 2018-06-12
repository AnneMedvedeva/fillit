/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <amedvedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 20:33:59 by amedvedi          #+#    #+#             */
/*   Updated: 2018/01/26 19:27:44 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfillit.h"

/*
** Reads 21 symbol at a time, after validation valid tetrimino is added
** to list.
*/

t_list	*read_tetr(int fd)
{
	int			rd;
	t_list		*list;
	t_tetr		*tetr;
	char		buf[21];
	char		l;

	list = NULL;
	l = 'A';
	while ((rd = read(fd, buf, 21)) >= 20)
	{
		if (rd == 21 && buf[20] != '\n')
			break ;
		buf[20] = 0;
		if (!(count_validation(buf)))
			break ;
		if (!(tetr = get_valid_el(ft_strsplit(buf, '\n'), l++)))
			return (free_lst(list));
		ft_lstadd(&list, ft_lstnew(tetr, sizeof(t_tetr)));
		ft_memdel((void**)&tetr);
		if (rd == 20)
			return (list);
	}
	free_lst(list);
	return (NULL);
}

/*
** Creates an elementin point structure to hold.
** coordinates of tetrimino.
*/

t_point	*create_point_arr(int **coords)
{
	t_point		*arr;
	int			i;

	arr = (t_point*)ft_memalloc(sizeof(t_point) * 4);
	i = 0;
	while (i < 4)
	{
		arr[i].x = coords[i][0];
		arr[i].y = coords[i][1];
		i++;
	}
	return (arr);
}

/*
** Creates an element in tetr structure.
*/

t_tetr	*create_tetr(int **coords, int h, int w, char l)
{
	t_tetr	*tetr;

	tetr = (t_tetr*)ft_memalloc(sizeof(t_tetr));
	if (tetr)
	{
		tetr->coords = create_point_arr(coords);
		tetr->height = h;
		tetr->width = w;
		tetr->letter = l;
		return (tetr);
	}
	return (NULL);
}

/*
** Frees allocated memory for tetr structure.
*/

void	free_tetr(void *data, size_t size)
{
	t_tetr *t;

	t = (t_tetr*)data;
	(void)size;
	ft_memdel((void**)&t->coords);
	ft_memdel((void**)&t);
}

/*
** Frees allocated memory for list.
*/

void	*free_lst(t_list *list)
{
	ft_lstdel(&list, free_tetr);
	return (NULL);
}
