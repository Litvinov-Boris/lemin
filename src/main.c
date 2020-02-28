/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 03:57:57 by svivienn          #+#    #+#             */
/*   Updated: 2020/02/28 21:13:59 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	t_lemin	*data;

	data = init_lemin();
	fd = open("./comment/directly_s_e", O_RDONLY);
	read_map(data);
	if (data->st_en_st->head == NULL || data->st_en_st->tail == NULL)
		error();
	suurballe(data);
	printf("%i, %i\n", data->ceiling, data->sum_dist);
	//suurballe(data);
	/*print_input(data);
	printf("\n%i\n", data->ants);*/
	print_rooms(data);
	close(fd);
	exit(0);
}