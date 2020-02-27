/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 03:56:58 by svivienn          #+#    #+#             */
/*   Updated: 2020/02/27 17:05:29 by svivienn         ###   ########.fr       */
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
# define IN		1
# define OUT	0

typedef struct	s_lst		t_lst;
typedef struct	s_lemin		t_lemin;
typedef struct	s_room		t_room;
typedef struct	s_subroom	t_subroom;
typedef struct	s_tube		t_tube;

struct s_tube
{
	t_subroom	*link;
	int			weight;
	int			turn;
};

struct			s_lst
{
	t_list		*head;
	t_list		*tail;
};

struct			s_lemin
{
	t_lst		*input;
	int			ants;
	t_lst		*rooms;
	t_lst		*st_en_st;
	int			trails;
	int			sum_dist;
	int			ceiling;
};

struct			s_room
{
	char		*name;
	int			x;
	int			y;
	t_subroom	*in;
	t_subroom	*out;
	t_room		*p_o;
	t_room		*p_n;
	t_room		*c_o;
	t_room		*c_n;
};

struct			s_subroom
{
	char		type;
	t_lst		*links;
	char		visited;
	t_room		*master;
	int			distance;
	t_subroom	*parent;
};

int	fd;

t_lemin		*init_lemin();
t_room		*init_room(char ***str);
t_subroom	*init_subroom(char type, t_room *master);
t_tube		*init_tube(t_subroom *link, int weight);

void		error();
int			room_replay(t_list *list, t_room *room);
t_room		*search_room(t_lemin *data, char *str);
int			tube_replay(t_list *list, t_room *room);
void		tube_pars1(t_room **room1, t_room **room2, t_lemin *data);

int			read_n_save(t_lemin *data);
void		lstadd_tail(t_lst *lst, t_list *list);

void		print_input(t_lemin *data);
void		print_rooms(t_lemin *data);
void		printlink(t_lemin *data);

int			is_valid(char *str);

void		read_map(t_lemin *data);
void		room_parser(t_lemin *data, int *mode, int str_t);

void		deikstra(t_lemin *data);
int			ne_pomestilos_v_suurbale(t_lemin *data);

int			suurballe(t_lemin *data);
void		build_map(t_lemin *data);
#endif