/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.t.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:21:17 by yoav              #+#    #+#             */
/*   Updated: 2023/03/23 12:14:46 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dda.h"
#include "unit_test.h"

void	test_dda_ray_infi(void)
{
	t_ray	r = {0};
	t_player p = {0};

	r.to_cast.radians = radian(0);
	dda_set_incrementor(&r, r.to_cast.radians);
	dda_set_ray_data(&r, r.to_cast.radians, &p);
	ray_increment(&r);
	ray_increment(&r);
	ray_increment(&r);
	CU_ASSERT_EQUAL(r.x_pos.x, 3.0);
	CU_ASSERT_EQUAL(r.x_pos.y, 0.0);
	
	p.pos = point_init(4, 4);
	r.to_cast.radians = radian(90);
	dda_set_incrementor(&r, r.to_cast.radians);
	dda_set_ray_data(&r, r.to_cast.radians, &p);
	ray_increment(&r);
	ray_increment(&r);
	ray_increment(&r);
	CU_ASSERT_EQUAL(r.y_pos.x, 4);
	CU_ASSERT_EQUAL(r.y_pos.y, 1);
	
	p.pos = point_init(11, 11);
	r.to_cast.radians = radian(180);
	dda_set_incrementor(&r, r.to_cast.radians);
	dda_set_ray_data(&r, r.to_cast.radians, &p);
	ray_increment(&r);
	ray_increment(&r);
	ray_increment(&r);
	CU_ASSERT_EQUAL(r.x_pos.x, 8);
	CU_ASSERT_EQUAL(r.x_pos.y, 11);

	p.pos = point_init(5, 60);
	r.to_cast.radians = radian(270);
	dda_set_incrementor(&r, r.to_cast.radians);
	dda_set_ray_data(&r, r.to_cast.radians, &p);
	ray_increment(&r);
	ray_increment(&r);
	ray_increment(&r);
	CU_ASSERT_EQUAL(r.y_pos.x, 5);
	CU_ASSERT_EQUAL(r.y_pos.y, 63);
}
