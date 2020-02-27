/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suurballe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 05:26:08 by svivienn          #+#    #+#             */
/*   Updated: 2020/02/27 16:12:24 by svivienn         ###   ########.fr       */
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

	if (room != ((t_room*)data->st_en_st->head->content)->out &&
		room != ((t_room*)data->st_en_st->tail->content)->out)
	{
		search_tube(room, &search, &search1);
		if (search1 == NULL)
			room->parent->links->head = search->next;
		else
			search1->next = search->next;
		if (room->parent->links->head == NULL)
			room->parent->links->tail = NULL;
		((t_tube*)search->content)->weight *= -1;
		((t_tube*)search->content)->link = room->parent;
		search->next = NULL;
		ft_lstadd(&room->links->head, search);
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
	deikstra(data);
	if (((t_room*)data->st_en_st->tail->content)->in->parent == NULL)
		error();
	if (((t_room*)data->st_en_st->tail->content)->in->parent ==
	((t_room*)data->st_en_st->head->content)->out)
		return (1);
	while (((t_room*)data->st_en_st->tail->content)->in->parent != NULL)
	{
		if (ne_pomestilos_v_suurbale(data) == 1)
			break ;
	}
	return (0);
}
