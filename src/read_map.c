/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 05:26:46 by svivienn          #+#    #+#             */
/*   Updated: 2020/01/31 10:08:12 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ants_parser(t_lemin *data, int *mode, int str_t)
{
	if (str_t != ANTS)
		error();
	else
	{
		data->ants = ft_atoi(data->input->tail->content);
		*mode = ROOM;
	}
}

void	read_map(t_lemin *data)
{
	int	str_t;
	int	mode;

	mode = ANTS;
	while (read_n_save(data))
	{
		str_t = is_valid(data->input->tail->content);
		if (str_t != COMENT)
		{
			if (mode == ANTS)
				ants_parser(data, &mode, str_t);
			//else if (mode == ROOM)
				//room_parser(data, &mode, str_t);
		}
	}
}