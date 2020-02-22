/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_save.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 04:10:23 by svivienn          #+#    #+#             */
/*   Updated: 2020/02/23 01:56:41 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	lstadd_tail(t_lst *lst, t_list *list)
{
	if (lst->head == NULL)
	{
		lst->head = list;
		lst->tail = lst->head;
	}
	else
	{
		lst->tail->next = list;
		lst->tail = lst->tail->next;
	}
}

int		read_n_save(t_lemin *data)
{
	int		ret;
	char	*str;
	t_list	*newintp;

	str = NULL;
	ret = get_next_line(fd, &str);
	if (ret < 0)
		error();
	if (ret > 0)
	{
		newintp = ft_lstnew(0, 0);
		newintp->content = str;
		newintp->content_size = ft_strlen(str);
		lstadd_tail(data->input, newintp);
	}
	return (ret);
}
