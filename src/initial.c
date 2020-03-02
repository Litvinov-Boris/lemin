/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boris <boris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 04:00:08 by svivienn          #+#    #+#             */
/*   Updated: 2020/03/02 06:58:32 by boris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_lst	*init_list(void)
{
	t_lst	*lst;

	if ((lst = (t_lst*)malloc(sizeof(t_lst))) == NULL)
		error();
	ft_bzero(lst, sizeof(t_lst));
	return (lst);
}

t_lemin			*init_lemin(void)
{
	t_lemin	*data;

	if ((data = (t_lemin*)malloc(sizeof(t_lemin))) == NULL)
		error();
	bzero(data, sizeof(t_lemin));
	data->input = init_list();
	data->rooms = init_list();
	data->st_en_st = init_list();
	data->ceiling = INT_MAX;
	return (data);
}

t_room			*init_room(t_lemin *data)
{
	t_room	*room;
	t_list	*work;
	char	*s1;
	int		i;

	if (!(room = (t_room*)malloc(sizeof(t_room))))
		error();
	ft_bzero(room, sizeof(t_room));
	i = ft_countwords(data->input->tail->content, ' ') - 2;
	s1 = ft_strchr(data->input->tail->content, ' ');
	while (--i > 0)
		s1 = ft_strchr(s1 + 1, ' ');
	i = s1 - (char*)(data->input->tail->content);
	if (!(room->name = (char*)malloc(sizeof(char) * (i + 1))))
		error();
	ft_strncpy(room->name, data->input->tail->content, i);
	room->x = ft_atoi(s1);
	room->y = ft_atoi(ft_strchr(s1, ' '));
	room->in = init_subroom(IN, room);
	room->out = init_subroom(OUT, room);
	if (!(work = ft_lstnew(0, 0)))
		error();
	work->content = init_tube(room->out, 0);
	lstadd_tail(room->in->links, work);
	return (room);
}

t_subroom		*init_subroom(char type, t_room *master)
{
	t_subroom	*subroom;

	if (!(subroom = (t_subroom*)malloc(sizeof(t_subroom))))
		error();
	ft_bzero(subroom, sizeof(t_subroom));
	subroom->type = type;
	subroom->master = master;
	subroom->links = init_list();
	return (subroom);
}

t_tube			*init_tube(t_subroom *link, int weight)
{
	t_tube	*tube;

	if (!(tube = (t_tube*)malloc(sizeof(t_tube))))
		error();
	bzero(tube, sizeof(t_tube));
	tube->link = link;
	tube->weight = weight;
	return (tube);
}
