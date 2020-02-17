/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 03:56:58 by svivienn          #+#    #+#             */
/*   Updated: 2020/02/17 04:55:09 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>
# include <limits.h>

# define COMENT	0
# define ANTS	1
# define ROOM	2
# define TUBE	3
# define START	4
# define END	5

typedef struct	s_lst	t_lst;
typedef struct	s_lemin	t_lemin;
typedef struct	s_room	t_room;


struct		s_lst
{
	t_list	*head;
	t_list	*tail;
};

struct		s_lemin
{
	t_lst	*input;
	int		ants;
};

struct		s_room
{
	char	*name;
};



int	fd;

t_lemin	*init_lemin();

void	error();

int		read_n_save(t_lemin *data);

void	print_input(t_lemin *data);

int		is_valid(char *str);

void	read_map(t_lemin *data);
#endif