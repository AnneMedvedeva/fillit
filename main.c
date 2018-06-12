/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <amedvedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 20:37:24 by amedvedi          #+#    #+#             */
/*   Updated: 2018/01/26 19:58:38 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfillit.h"

/*
** Prints error message on a standart output.
*/

static	void	print_err(void)
{
	ft_putendl("error");
	exit(1);
}

/*
** Prints map and frees allocated memory for list and map.
*/

static void		print_free(t_map **map, t_list **list)
{
	print_map(*map);
	free_map(*map);
	free_lst(*list);
}

/*
** Function to solve map.
** If placement fails, size of the map increase.
*/

static t_map	*solve_map(t_map **map, t_list **list, int size)
{
	int		tmp_size;

	tmp_size = size;
	while (!(solve(*map, *list)))
	{
		free_map(*map);
		*map = create_map(++tmp_size);
	}
	return (*map);
}

int				main(int ac, char **av)
{
	int		size;
	t_list	*list;
	t_map	*map;

	if (ac == 2)
	{
		list = read_tetr(open(av[1], O_RDONLY));
		if (!list)
			print_err();
		else if (ft_lstcount(list) > 26)
		{
			free_lst(list);
			print_err();
		}
		ft_lstrev(&list);
		size = high_sqrt(ft_lstcount(list) * 4);
		map = create_map(size);
		map = solve_map(&map, &list, size);
		print_free(&map, &list);
	}
	else
		ft_putendl("usage: fillit input_file");
	return (0);
}
