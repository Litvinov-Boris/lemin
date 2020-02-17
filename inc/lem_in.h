/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boris <boris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 03:56:58 by svivienn          #+#    #+#             */
/*   Updated: 2020/02/17 11:31:41 by boris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>
# include <limits.h>

# define COMENT	0
# define ANTS	1
# define ROOM	2
# define TUBE	3
# define START	4
# define END	5

typedef struct	s_lst	t_lst;
typedef struct	s_lemin	t_lemin;
typedef struct	s_room	t_room;


struct		s_lst
{
	t_list	*head;
	t_list	*tail;
};

struct		s_lemin
{
	t_lst	*input;
	int		ants;
	t_lst	*rooms;
	char	st_en_st;
};

struct		s_room
{
	char	*name;
};



int	fd;

t_lemin	*init_lemin();
t_room	*init_room(char *str);

void	error();

int		read_n_save(t_lemin *data);
void	lstadd_tail(t_lst *lst, t_list *list);

void	print_input(t_lemin *data);
void	print_rooms(t_lemin *data);

int		is_valid(char *str);

void	read_map(t_lemin *data);
void	room_parser(t_lemin *data, int *mode, int str_t);
#endif