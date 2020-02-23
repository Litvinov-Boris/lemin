/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suurballe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 05:26:08 by svivienn          #+#    #+#             */
/*   Updated: 2020/02/23 05:52:31 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	suurballe(t_lemin *data)
{
	deikstra(data);
	if (((t_room*)data->st_en_st->tail->content)->in->parent == NULL)
		error();
	if (((t_room*)data->st_en_st->tail->content)->in->parent ==
	((t_room*)data->st_en_st->head->content)->out)
		return (1);
	
}