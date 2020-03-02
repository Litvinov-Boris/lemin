/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boris <boris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 05:26:46 by svivienn          #+#    #+#             */
/*   Updated: 2020/03/02 06:35:42 by boris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ants_parser(t_lemin *data, int *mode, int str_t)
{
	if (str_t != ANTS)
		error();
	else
	{
		data->ants = ft_atoi(data->input->tail->content);
		if (data->ants <= 0)
			error();
		*mode = ROOM;
	}
}

static void	start_and_parser(t_lemin *data, int str_t)
{
	int str_t1;

	if (!(read_n_save(data)))
		error();
	str_t1 = is_valid(data->input->tail->content);
	while (str_t1 == COMENT)
	{
		if (!(read_n_save(data)))
			error();
		str_t1 = is_valid(data->input->tail->content);
	}
	if (str_t1 == ROOM)
		room_parser(data, &str_t1, str_t1);
	else
		error();
	if (str_t == START)
		data->st_en_st->head = data->rooms->tail;
	else
		data->st_en_st->tail = data->rooms->tail;
}

static void	tube_parser(int str_t, t_lemin *data)
{
	t_room	*room1;
	t_room	*room2;
	t_list	*tube;
	t_list	*tube2;

	if (str_t != TUBE)
		error();
	tube_pars1(&room1, &room2, data);
	if (tube_replay(room1->out->links->head, room2) ||
							tube_replay(room2->out->links->head, room1))
		error();
	tube = ft_lstnew(0, 0);
	tube2 = ft_lstnew(0, 0);
	if (!tube || !tube2)
		error();
	tube->content = init_tube(room2->in, 1);
	tube2->content = init_tube(room1->in, 1);
	lstadd_tail(room1->out->links, tube);
	lstadd_tail(room2->out->links, tube2);
}

void		room_parser(t_lemin *data, int *mode, int str_t)
{
	t_list	*work;

	if (str_t == ROOM)
	{
		if (!(work = ft_lstnew(0, 0)))
			error();
		work->content = init_room(data);
		if (room_replay((data->rooms->head), work->content))
			error();
		lstadd_tail(data->rooms, work);
	}
	else if ((str_t == START && data->st_en_st->head == NULL) ||
		(str_t == END && data->st_en_st->tail == NULL))
		start_and_parser(data, str_t);
	else if (str_t == TUBE)
	{
		*mode = TUBE;
		tube_parser(str_t, data);
	}
	else
		error();
}

void		read_map(t_lemin *data)
{
	int	str_t;
	int	mode;

	mode = ANTS;
	while (read_n_save(data))
	{
		str_t = is_valid(data->input->tail->content);
		if (str_t != COMENT)
		{
			if (mode == ANTS)
				ants_parser(data, &mode, str_t);
			else if (mode == ROOM)
				room_parser(data, &mode, str_t);
			else if (mode == TUBE)
				tube_parser(str_t, data);
		}
	}
}
