/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boris <boris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 05:26:46 by svivienn          #+#    #+#             */
/*   Updated: 2020/02/17 10:37:56 by boris            ###   ########.fr       */
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

void	room_parser(t_lemin *data, int *mode, int str_t)
{
	t_list	*work;
	char	**split;

	if (str_t == ROOM)
	{
		if (!(work = (t_list*)malloc(sizeof(t_list))))
			error();
		if (!(split = ft_strsplit(data->input->tail->content, ' ')))
			error();
		work->content = init_room(split[0]);
		free(split[1]);
		free(split[2]);
		free(split);
		lstadd_tail(data->rooms, work);
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
			else if (mode == ROOM)
				room_parser(data, &mode, str_t);
		}
	}
}