/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boris <boris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 03:57:57 by svivienn          #+#    #+#             */
/*   Updated: 2020/02/17 10:37:25 by boris            ###   ########.fr       */
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
	printf("%i\n", data->ants);
	print_rooms(data);
	close(fd);
	return (0);
}