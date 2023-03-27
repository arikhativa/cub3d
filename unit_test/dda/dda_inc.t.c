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
#include "unit_test_util.h"

void	test_ray_set_incrementor(void)
{
	t_ray	r = {0};
	double	rad = radian(0);
	
	ray_set_incrementor(&r, rad);
	CU_ASSERT_EQUAL(r.incrementor.x, 1);
	CU_ASSERT_EQUAL(r.incrementor.y, 0);

	rad = radian(45);
	ray_set_incrementor(&r, rad);
	CU_ASSERT_EQUAL(r.incrementor.x, 1);
	CU_ASSERT_EQUAL(r.incrementor.y, 1);

	rad = radian(90);
	ray_set_incrementor(&r, rad);
	CU_ASSERT_EQUAL(r.incrementor.x, 0);
	CU_ASSERT_EQUAL(r.incrementor.y, 1);

	rad = radian(135);
	ray_set_incrementor(&r, rad);
	CU_ASSERT_EQUAL(r.incrementor.x, -1);
	CU_ASSERT_EQUAL(r.incrementor.y, 1);

	rad = radian(180);
	ray_set_incrementor(&r, rad);
	CU_ASSERT_EQUAL(r.incrementor.x, -1);
	CU_ASSERT_EQUAL(r.incrementor.y, 0);

	rad = radian(180 + 45);
	ray_set_incrementor(&r, rad);
	CU_ASSERT_EQUAL(r.incrementor.x, -1);
	CU_ASSERT_EQUAL(r.incrementor.y, -1);

	rad = radian(270);
	ray_set_incrementor(&r, rad);
	CU_ASSERT_EQUAL(r.incrementor.x, 0);
	CU_ASSERT_EQUAL(r.incrementor.y, -1);

	rad = radian(270 + 45);
	ray_set_incrementor(&r, rad);
	CU_ASSERT_EQUAL(r.incrementor.x, 1);
	CU_ASSERT_EQUAL(r.incrementor.y, -1);

	rad = radian(360);
	ray_set_incrementor(&r, rad);
	CU_ASSERT_EQUAL(r.incrementor.x, 1);
	CU_ASSERT_EQUAL(r.incrementor.y, 0);

	rad = radian(360 + 1);
	ray_set_incrementor(&r, rad);
	CU_ASSERT_EQUAL(r.incrementor.x, 1);
	CU_ASSERT_EQUAL(r.incrementor.y, 1);

	rad = radian(-1);
	ray_set_incrementor(&r, rad);
	CU_ASSERT_EQUAL(r.incrementor.x, 1);
	CU_ASSERT_EQUAL(r.incrementor.y, -1);
}
