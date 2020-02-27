/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 04:14:29 by svivienn          #+#    #+#             */
/*   Updated: 2020/02/27 17:08:28 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	error(void)
{
	perror("ERROR");
	exit(1);
}

int		room_replay(t_list *list, t_room *room)
{
	t_list	*work;

	work = list;
	while (work != NULL)
	{
		if (!(ft_strcmp(((t_room*)work->content)->name, room->name)) ||
						(((t_room*)work->content)->x == room->x &&
										((t_room*)work->content)->y == room->y))
			return (1);
		work = work->next;
	}
	return (0);
}

t_room	*search_room(t_lemin *data, char *str)
{
	t_list	*work;

	work = data->rooms->head;
	while (work != NULL)
	{
		if (!(ft_strcmp(((t_room*)work->content)->name, str)))
			return (work->content);
		work = work->next;
	}
	return (NULL);
}

int		tube_replay(t_list *list, t_room *room)
{
	t_list	*work;

	work = list;
	while (work != NULL)
	{
		if (((t_tube*)work->content)->link == room->in)
			return (1);
		work = work->next;
	}
	return (0);
}

void	tube_pars1(t_room **room1, t_room **room2, t_lemin *data)
{
	char	**split;

	if (!(split = ft_strsplit(data->input->tail->content, '-')))
		error();
	*room1 = search_room(data, split[0]);
	*room2 = search_room(data, split[1]);
	if (!(*room1) || !(*room2) || *room1 == *room2)
		error();
	free(split[0]);
	free(split[1]);
	free(split);
}
