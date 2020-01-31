/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 04:00:08 by svivienn          #+#    #+#             */
/*   Updated: 2020/01/31 04:09:39 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_lst	*init_list()
{
	t_lst	*lst;

	lst = (t_lst*)malloc(sizeof(t_lst));
	ft_bzero(lst, sizeof(t_lst));
	return (lst);
}

t_lemin	*init_lemin()
{
	t_lemin	*data;

	data = (t_lemin*)malloc(sizeof(t_lemin));
	bzero(data, sizeof(t_lemin));
	data->input = init_list();
	return (data);
}
