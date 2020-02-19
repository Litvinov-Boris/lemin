/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 04:14:29 by svivienn          #+#    #+#             */
/*   Updated: 2020/02/19 06:38:04 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	error()
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
			return (work);
		work = work->next;
	}
	return (NULL);
}