/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deikstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 02:02:45 by svivienn          #+#    #+#             */
/*   Updated: 2020/02/27 16:59:46 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			init_deikstra(t_lemin *data)
{
	t_list	*work;

	work = data->rooms->head;
	while (work != NULL)
	{
		((t_room*)work->content)->in->distance = INT_MAX;
		((t_room*)work->content)->in->parent = NULL;
		((t_room*)work->content)->in->visited = 0;
		((t_room*)work->content)->out->distance = INT_MAX;
		((t_room*)work->content)->out->parent = NULL;
		((t_room*)work->content)->out->visited = 0;
		work = work->next;
	}
	((t_room*)data->st_en_st->head->content)->in->distance = 0;
}

static t_subroom	*search_min(t_lemin *data)
{
	t_list		*work;
	t_subroom	*search;
	int			min_s;

	work = data->rooms->head;
	min_s = INT_MAX;
	search = NULL;
	while (work != NULL)
	{
		if (((t_room*)work->content)->in->distance < min_s &&
									((t_room*)work->content)->in->visited == 0)
		{
			search = ((t_room*)work->content)->in;
			min_s = search->distance;
		}
		if (((t_room*)work->content)->out->distance < min_s &&
									((t_room*)work->content)->out->visited == 0)
		{
			search = ((t_room*)work->content)->out;
			min_s = search->distance;
		}
		work = work->next;
	}
	return (search);
}

static void			change_dist(t_subroom *data)
{
	t_list	*work;
	t_tube	*tube;

	work = data->links->head;
	while (work != NULL)
	{
		tube = work->content;
		if (tube->link->distance > (data->distance + (tube->weight)))
		{
			tube->link->parent = data;
			tube->link->distance = (data->distance + (tube->weight));
		}
		work = work->next;
	}
	data->visited = 1;
}

void				deikstra(t_lemin *data)
{
	t_subroom	*work;

	init_deikstra(data);
	while ((work = search_min(data)))
	{
		change_dist(work);
	}
}

int					ne_pomestilos_v_suurbale(t_lemin *data)
{
	int	work;

	work = data->sum_dist +
	((t_room*)data->st_en_st->tail->content)->in->distance - 1 + data->ants;
	work = (work % (data->trails + 1)) == 0 ? work / (data->trails + 1) :
			(work / (data->trails + 1)) + 1;
	if (data->ceiling >= work)
	{
		data->ceiling = work;
		data->trails++;
		data->sum_dist += ((t_room*)data->st_en_st->tail->content)->out->
				distance - 1;
	}
	else
		return (1);
	build_map(data);
	deikstra(data);
	return (0);
}
