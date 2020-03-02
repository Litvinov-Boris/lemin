/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boris <boris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 05:28:37 by svivienn          #+#    #+#             */
/*   Updated: 2020/03/02 07:01:28 by boris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	is_coment(char *str)
{
	if (str[0] == '#' && ft_strcmp(str, "##start") &&
							ft_strcmp(str, "##end"))
		return (1);
	else
		return (0);
}

static int	is_ants(char *str)
{
	if (ft_countwords(str, ' ') == 1)
	{
		while (*str != '\0')
		{
			if (!(ft_isdigit(*str)))
				return (0);
			str++;
		}
		return (1);
	}
	return (0);
}

static int	is_room(char *str)
{
	char	*s1;

	if (*str != 'L' && *str != '#')
	{
		s1 = str + ft_strlen(str) - 1;
		while (*s1 != ' ')
		{
			if (!(ft_isdigit(*s1)))
				return (0);
			s1--;
		}
		while (*(--s1) != ' ')
			if (!(ft_isdigit(*s1)))
				return (0);
		while (str != s1)
		{
			if (*str == '-' || !(ft_isprint(*str)))
				return (0);
			str++;
		}
		return (1);
	}
	return (0);
}

static int	is_tube(char *str)
{
	return (ft_countwords(str, '-') == 2) ? 1 : 0;
}

int			is_valid(char *str)
{
	if (is_coment(str))
		return (COMENT);
	else if (is_tube(str))
		return (TUBE);
	else if (is_room(str))
		return (ROOM);
	else if (!ft_strcmp(str, "##start"))
		return (START);
	else if (!ft_strcmp(str, "##end"))
		return (END);
	else if (is_ants(str))
		return (ANTS);
	else
		return (-1);
}
