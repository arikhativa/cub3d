/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.t.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:59:44 by ycarro            #+#    #+#             */
/*   Updated: 2023/03/22 12:10:57 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "tab.h"
#include "collision.h"
#include "unit_test.h"

void    test_check_collision(void)
{
    char    *ex_map[] = {
        "000",
        "010",
        "000",
    };
    t_error_code    collision;
    t_ray           ex_ray;
    t_point         collider;

    ex_ray.x_pos = point_init(0, 0);
    ex_ray.y_pos = point_init(1, 1);
    collision = is_collides(&ex_ray, ex_map, &collider);
    CU_ASSERT_EQUAL(Y_COLLISION, collision);
    ex_ray.x_pos = point_init(0, 0);
    ex_ray.y_pos = point_init(2, 2);
    collision = is_collides(&ex_ray, ex_map, &collider);
    CU_ASSERT_EQUAL(NO_COLLISION, collision);
    ex_ray.x_pos = point_init(1, 1);
    ex_ray.y_pos = point_init(0, 0);
    collision = is_collides(&ex_ray, ex_map, &collider);
    CU_ASSERT_EQUAL(X_COLLISION, collision);
    ex_ray.x_pos = point_init(2, 2);
    ex_ray.y_pos = point_init(0, 0);
    collision = is_collides(&ex_ray, ex_map, &collider);
    CU_ASSERT_EQUAL(NO_COLLISION, collision);
}