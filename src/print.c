/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 04:22:22 by svivienn          #+#    #+#             */
/*   Updated: 2020/02/19 03:05:36 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_input(t_lemin *data)
{
	t_list *work;

	work = data->input->head;
	while (work != NULL)
	{
		write (1, work->content, work->content_size);
		write (1, "\n", 1);
		work = work->next;
	}
}

void	print_rooms(t_lemin *data)
{
	t_list *work;

	work = data->rooms->head;
	while (work != NULL)
	{
		printf("%s\n", ((t_room*)(work->content))->name);
		work = work->next;
	}
	printf("\n%s\n%s", ((t_room*)(data->st_en_st->head->content))->name,
			((t_room*)(data->st_en_st->tail->content))->name);
}