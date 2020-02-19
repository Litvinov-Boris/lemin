/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 04:00:08 by svivienn          #+#    #+#             */
/*   Updated: 2020/02/19 06:25:48 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_lst	*init_list()
{
	t_lst	*lst;

	if ((lst = (t_lst*)malloc(sizeof(t_lst))) == NULL)
		error();
	ft_bzero(lst, sizeof(t_lst));
	return (lst);
}

t_lemin	*init_lemin()
{
	t_lemin	*data;

	if ((data = (t_lemin*)malloc(sizeof(t_lemin))) == NULL)
		error();
	bzero(data, sizeof(t_lemin));
	data->input = init_list();
	data->rooms = init_list();
	data->st_en_st = init_list();
	return (data);
}

t_room	*init_room(char ***str)
{
	t_room	*room;
	t_list	*work;

	if (!(room = (t_room*)malloc(sizeof(t_room))))
		error();
	ft_bzero(room, sizeof(t_room));
	room->name = (*str)[0];
	room->in = init_subroom(IN, room);
	room->out = init_subroom(OUT, room);
	room->x = ft_atoi((*str)[1]);
	room->y = ft_atoi((*str)[2]);
	if (!(work = ft_lstnew(0,0)))
		error();
	work->content = init_tube(room->out, 0);
	lstadd_tail(room->in->links, work);
	free((*str)[1]);
	free((*str)[2]);
	free(*str);
	return (room);
}

t_subroom	*init_subroom(char type, t_room *master)
{
	t_subroom	*subroom;

	if (!(subroom = (t_subroom*)malloc(sizeof(t_subroom))))
		error();
	ft_bzero(subroom, sizeof (t_subroom));
	subroom->type = type;
	subroom->master = master;
	subroom->links = init_list();
	return(subroom);
}

t_tube		*init_tube(t_subroom *link, int weight)
{
	t_tube	*tube;

	if (!(tube = (t_tube*)malloc(sizeof(t_tube))))
		error();
	bzero(tube, sizeof(t_tube));
	tube->link = link;
	tube->weight = weight;
	return (tube);
}