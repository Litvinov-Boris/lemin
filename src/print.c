/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boris <boris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 04:22:22 by svivienn          #+#    #+#             */
/*   Updated: 2020/02/27 13:56:38 by boris            ###   ########.fr       */
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
		printf ("%s\n", ((t_room*)work->content)->name);
		if (((t_room*)work->content)->p_o != NULL)
			printf ("po - %s", ((t_room*)work->content)->p_o->name);
		if (((t_room*)work->content)->c_o != NULL)
			printf (", co - %s", ((t_room*)work->content)->c_o->name);
		printf("\n\n");
		work = work->next;
	}
}

void	printlink(t_lemin *data)
{
	t_list	*work;
	t_list	*work1;
	work = data->rooms->head;
	while (work != NULL)
	{
		printf("%s:\n", ((t_room*)work->content)->name);
		work1 = ((t_room*)work->content)->in->links->head;
		printf("in: ");
		while (work1 !=NULL)
		{
			printf("%s/%i, ", ((t_tube*)work1->content)->link->master->name, ((t_tube*)work1->content)->link->type);
			work1 = work1->next;
		}
		printf("\nout: ");
		work1 = ((t_room*)work->content)->out->links->head;
		while (work1 !=NULL)
		{
			printf("%s/%i, ", ((t_tube*)work1->content)->link->master->name, ((t_tube*)work1->content)->link->type);
			work1 = work1->next;
		}
		printf("\n");
		work = work->next;
	}
	printf ("_______________________________________\n");
}