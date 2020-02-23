/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suurballe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 05:26:08 by svivienn          #+#    #+#             */
/*   Updated: 2020/02/23 11:04:44 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	search_tube(t_subroom *data, t_list **search, t_list **presearch)
{
	*search = data->parent->links->head;
	*presearch = NULL;
	if (((t_tube*)(*search)->content)->link != data)
	{
		while (*search && ((t_tube*)(*search)->content)->link != data)
		{
			*presearch = *search;
			*search = (*search)->next;
		}
		if (*search == NULL)
			error();
	}
}

static void	tube_turn(t_lemin *data, t_subroom *room)
{
	t_list	*search;
	t_list	*search1;
	t_list	*newtube;

	if (room != ((t_room*)data->st_en_st->head->content)->out &&
		room != ((t_room*)data->st_en_st->tail->content)->out)
	{
		search_tube(room, &search, &search1);
		if (((t_tube*)search->content)->turn == 0)
		{
			if (search1 == NULL)
				room->parent->links->head = search->next;
			else
				search1->next = search->next;
			((t_tube*)search->content)->turn = 1;
			((t_tube*)search->content)->weight *= -1;
			((t_tube*)search->content)->link = room->parent;
			lstadd_tail(room->links, search);
		}
	}
}

static void	homecoming(t_lemin *data)
{
	t_subroom *room;

	room = ((t_room*)data->st_en_st->tail->content)->out;
	while (room->parent)
	{
		tube_turn(data, room);
		if (room->master != room->parent->master)
		{
			room->master->p_n = room->parent->master;
			room->parent->master->c_n = room->master;
		}
		room = room->parent;
	}
	((t_room*)data->st_en_st->head->content)->p_o = NULL;
	((t_room*)data->st_en_st->head->content)->c_o = NULL;
}

void		build_map(t_lemin *data)
{
	t_list	*work;
	t_room	*work1;

	homecoming(data);
	work = data->rooms->head;
	while (work != NULL)
	{
		work1 = work->content;
		if (work1->p_o == NULL)
			work1->p_o = work1->p_n;
		else if (work1->p_o == work1->c_n)
			work1->p_o = work1->p_n;
		if (work1->c_o == NULL)
			work1->c_o = work1->c_n;
		else if (work1->c_o == work1->p_n)
			work1->c_o = work1->c_n;
		work = work->next;
	}
}

int			suurballe(t_lemin *data)
{
	int	work;

	deikstra(data);
	if (((t_room*)data->st_en_st->tail->content)->in->parent == NULL)
		error();
	if (((t_room*)data->st_en_st->tail->content)->in->parent ==
	((t_room*)data->st_en_st->head->content)->out)
		return (1);
	data->trails = 1;
	data->sum_dist = ((t_room*)data->st_en_st->tail->content)->in->distance - 1;
	data->ceiling = data->sum_dist + data->ants;
	while (((t_room*)data->st_en_st->tail->content)->in->parent != NULL)
	{
		ne_pomestilos_v_suurbale(data, &work);
		if (data->ceiling >= work)
		{
			data->ceiling = work;
			data->trails++;
			data->sum_dist += ((t_room*)data->st_en_st->tail->content)->out->
					distance - 1;
		}
		else
			break ;
	}
	return (0);
}
