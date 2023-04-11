/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_set_incrementor.t.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:21:17 by yoav              #+#    #+#             */
/*   Updated: 2023/04/11 16:02:12 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dda.h"
#include "unit_test.h"
#include "unit_test_util.h"

void	test_ray_set_incrementor(void)
{
	t_ray	r;
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