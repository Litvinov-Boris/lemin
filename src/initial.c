/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boris <boris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 04:00:08 by svivienn          #+#    #+#             */
/*   Updated: 2020/02/17 10:44:22 by boris            ###   ########.fr       */
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
	return (data);
}

t_room	*init_room(char *str)
{
	t_room	*room;

	if (!(room = (t_room*)malloc(sizeof(t_room))))
		error();
	ft_bzero(room, sizeof(t_room));
	room->name = str;
	return (room);
}