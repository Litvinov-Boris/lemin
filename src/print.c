/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 04:22:22 by svivienn          #+#    #+#             */
/*   Updated: 2020/01/31 04:24:23 by svivienn         ###   ########.fr       */
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