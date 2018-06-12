/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <amedvedi@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 20:25:52 by amedvedi          #+#    #+#             */
/*   Updated: 2018/01/24 22:02:15 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFILLIT_H
# define LIBFILLIT_H

# include <string.h>
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct			s_point
{
	int					x;
	int					y;
}						t_point;
typedef struct			s_tetr
{
	t_point				*coords;
	int					height;
	int					width;
	char				letter;
}						t_tetr;
typedef struct			s_map
{
	char				**array;
	int					size;
}						t_map;

int						count_validation(char *str);
int						**get_coords(char **data, int h, int w);
t_tetr					*get_valid_el(char **data, char c);
t_list					*read_tetr(int fd);
t_point					*create_point_arr(int **coords);
t_tetr					*create_tetr(int **coords, int h, int w, char l);
void					free_tetr(void *data, size_t size);
void					*free_lst(t_list *list);
void					free_map(t_map *map);
t_map					*create_map(int size);
void					print_map(t_map *map);
void					set_tetr(t_tetr *t, t_map *map, t_point p, char c);
int						place_tetr(t_tetr *t, t_map *map, t_point p);
int						solve(t_map *map, t_list *list);
int						find_coords_y1_x1(char **tetr);
int						find_coords_y2_x2(char **tetr);
void					transp_matrix(char **tetr);
char					**trim_data(char **data, t_point p1, t_point p2);
int						is_sharp(char *str);
int						ft_lstcount(t_list *list);
int						high_sqrt(int n);

#endif
