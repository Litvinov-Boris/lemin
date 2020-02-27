/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 03:57:57 by svivienn          #+#    #+#             */
/*   Updated: 2020/02/27 16:09:12 by svivienn         ###   ########.fr       */
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
	fd = open("./test1", O_RDONLY);
	read_map(data);
	suurballe(data);
	printf("%i, %i", data->ceiling, data->sum_dist);
	//suurballe(data);
	/*print_input(data);
	printf("\n%i\n", data->ants);*/
	print_rooms(data);
	close(fd);
	exit(0);
}