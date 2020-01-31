/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_save.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 04:10:23 by svivienn          #+#    #+#             */
/*   Updated: 2020/01/31 04:27:10 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	lstadd_tail(t_lst *lst, t_list *list)
{
	if (lst->head == NULL)
	{
		lst->head = list;
		lst->tail = list;
	}
	else
	{
		lst->tail->next = list;
		lst->tail = lst->tail->next;
	}
}

int			read_n_save(t_lemin *data)
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
		newintp = ft_lstnew(str, ft_strlen(str));
		lstadd_tail(data->input, newintp);
		free(str);
	}
	return (ret);
}