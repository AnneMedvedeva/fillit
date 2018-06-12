/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <amedvedi@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 16:42:31 by amedvedi          #+#    #+#             */
/*   Updated: 2018/01/24 21:04:45 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfillit.h"

/*
** Validates amount of dots and sharps.
** Also validates for another unvalid characters.
*/

int				count_validation(char *str)
{
	int i;
	int dots;
	int sharps;

	i = 0;
	dots = 0;
	sharps = 0;
	while (str[i])
	{
		if (str[i] == '.')
			dots++;
		if (str[i] == '#')
			sharps++;
		if (str[i] != '\n' && str[i] != '.' && str[i] != '#')
			return (0);
		i++;
	}
	if ((dots != 12) || (sharps != 4))
		return (0);
	return (1);
}

/*
** Validates that the tetrimino has 4 elements in string.
** And has 4 strings.
*/

static	int		valid_stroke(char **data)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (data[i])
	{
		if (ft_strlen(data[i]) == 4)
			count++;
		i++;
	}
	if (count != 4)
		return (1);
	return (0);
}

/*
** Identically to bond_plus it counts connections between sharps
** but from lower right corner of matrix.
*/

static	int		bond_minus(char **str, int h, int w)
{
	int	i;
	int	j;
	int	bond;

	i = h;
	bond = 0;
	while (i >= 0)
	{
		j = w;
		while (j >= 0)
		{
			if (str[i][j] == '#' && j >= 1 && str[i][j - 1] == '#')
				bond++;
			if (str[i][j] == '#' && i >= 1 && str[i - 1][j] == '#')
				bond++;
			j--;
		}
		i--;
	}
	return (bond);
}

/*
** Counts connections between sharps from upper left corner of
** tetrimino matrix.
*/

static	int		bond_plus(char **str, int h, int w)
{
	int	i;
	int	j;
	int	bond;

	i = 0;
	bond = 0;
	while (i <= h)
	{
		j = 0;
		while (j <= w)
		{
			if (str[i][j] == '#' && (j <= w - 1) && str[i][j + 1] == '#')
				bond++;
			if (str[i][j] == '#' && (i <= h - 1) && str[i + 1][j] == '#')
				bond++;
			j++;
		}
		i++;
	}
	if (bond + bond_minus(str, h, w) >= 6)
		return (1);
	return (0);
}

/*
** Finds coordinates and trims given piece to tetrimino.
** After successed validation is added in tetr structure.
*/

t_tetr			*get_valid_el(char **data, char c)
{
	t_tetr		*tetr;
	char		**trimmed;
	t_point		p1;
	t_point		p2;
	int			**coords;

	p1.y = find_coords_y1_x1(data);
	p2.y = find_coords_y2_x2(data);
	transp_matrix(data);
	p1.x = find_coords_y1_x1(data);
	p2.x = find_coords_y2_x2(data);
	transp_matrix(data);
	if (!(valid_stroke(data)))
	{
		trimmed = trim_data(data, p1, p2);
		if (bond_plus(trimmed, p2.y - p1.y, p2.x - p1.x))
		{
			coords = get_coords(trimmed, p2.y - p1.y + 1, p2.x - p1.x + 1);
			tetr = create_tetr(coords, p2.y - p1.y + 1, p2.x - p1.x + 1, c);
			ft_memdel((void**)&trimmed);
			ft_memdel((void**)&coords);
			return (tetr);
		}
	}
	return (NULL);
}
