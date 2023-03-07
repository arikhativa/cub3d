/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.t.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:59:44 by ycarro            #+#    #+#             */
/*   Updated: 2023/03/07 18:15:25 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "tab.h"
#include "collision.h"
#include "unit_test.h"

void	test_check_collision(void)
{
	t_error_code	collision;
	t_ray			ex_ray;
	t_point			collider;
	char			**ex_map;

	tab_create(&ex_map, 200);
	ex_map[0] = calloc(20, sizeof(char));
	ex_map[1] = calloc(20, sizeof(char));
	ex_map[2] = calloc(20, sizeof(char));
	ex_map[3] = calloc(20, sizeof(char));
	ex_map[4] = calloc(20, sizeof(char));
	ex_ray.x_pos.x = 0;
	ex_ray.x_pos.y = 0;
	ex_ray.y_pos.x = 100;
	ex_ray.y_pos.y = 100;
	ex_map[1][1] = '1';
	collision = is_collides(&ex_ray, ex_map, &collider);
	CU_ASSERT_EQUAL(Y_COLLISION, collision);
}