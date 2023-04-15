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

void	rev_loop_map_print(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		++i;
	--i;
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
	rev_loop_map_print(m->map);
	printf("NOTE - map indexing start from bottom left (not top left)\n");
}
