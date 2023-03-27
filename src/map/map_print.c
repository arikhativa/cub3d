/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/02/15 13:58:46 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void	rev_loop_map_print(char **map, int size)
{
	int	i;

	i = size - 1;
	while (i >= 0)
	{
		printf("%s\n", map[i]);
		--i;
	}
}

void	map_print(t_map *m)
{
	printf("map:\nsize: ");
	point_print(m->size);
	printf("\n");
	plane_mngr_print(m->pm);
	player_print(m->p);
	printf("\n");
	rev_loop_map_print(m->map, m->size.y);
	printf("NOTE - map indexing start from bottom left (not top left)\n");
}
