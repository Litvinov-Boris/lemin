/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 04:22:22 by svivienn          #+#    #+#             */
/*   Updated: 2020/02/23 03:16:46 by svivienn         ###   ########.fr       */
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
	t_list	*work1;

	work = data->rooms->head;
	while (work != NULL)
	{
		/*printf("%s %i %i\nins:\n", ((t_room*)(work->content))->name, ((t_room*)(work->content))->x, ((t_room*)(work->content))->y);
		work1 = ((t_room*)(work->content))->in->links->head;
		while (work1 != NULL)
		{
			printf ("%s-%i, ", ((t_tube*)work1->content)->link->master->name, ((t_tube*)work1->content)->link->type);
			work1 = work1->next;
		}
		printf("\nout:\n");
		work1 = ((t_room*)(work->content))->out->links->head;
		while (work1 != NULL)
		{
			printf ("%s-%i, ", ((t_tube*)work1->content)->link->master->name, ((t_tube*)work1->content)->link->type);
			work1 = work1->next;
		}
		printf("\n\n");*/
		printf("%s\nin dist-%i ", ((t_room*)work->content)->name, ((t_room*)work->content)->in->distance);
		if (work != data->st_en_st->head)
			printf("parent - %s-%i", ((t_room*)work->content)->in->parent->master->name, ((t_room*)work->content)->in->parent->type);
		printf("\n");
		printf("out dist-%i ",((t_room*)work->content)->out->distance);
		printf("parent - %s-%i\n\n", ((t_room*)work->content)->out->parent->master->name, ((t_room*)work->content)->out->parent->type);
		work = work->next;
	}
}