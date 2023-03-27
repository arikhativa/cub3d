/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utest.t.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:21:17 by yoav              #+#    #+#             */
/*   Updated: 2023/02/14 12:27:39 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "unit_test.h"

void	test_inc_y_63(void)
{
	t_ray	r = {0};
	t_player p = {0};
	t_fpoint	ret;

	r.to_cast.radians = radian(63.434948822922);
	p.pos.y = 2;
	p.pos.x = 10;
	ray_set_incrementor(&r, r.to_cast.radians);
	rey_init(&r, r.to_cast.radians, p.pos);

	ret = increment_y(&r);
	CU_ASSERT_DOUBLE_EQUAL(ret.x, 10.5, 0.0000000001);
	CU_ASSERT_DOUBLE_EQUAL(ret.y, 3, 0.0000000001);
	r.y_pos = ret;
	ret = increment_y(&r);
	CU_ASSERT_DOUBLE_EQUAL(ret.x, 11.0, 0.0000000001);
	CU_ASSERT_DOUBLE_EQUAL(ret.y, 4, 0.0000000001);
	r.y_pos = ret;
	ret = increment_y(&r);
	CU_ASSERT_DOUBLE_EQUAL(ret.x, 11.5, 0.0000000001);
	CU_ASSERT_DOUBLE_EQUAL(ret.y, 5, 0.0000000001);
}

void	test_inc_y_165(void)
{
	t_ray	r = {0};
	t_player p = {0};
	t_fpoint	ret;

	r.to_cast.radians = radian(165.96375653207);
	p.pos.y = 5;
	p.pos.x = -1;
	ray_set_incrementor(&r, r.to_cast.radians);
	rey_init(&r, r.to_cast.radians, p.pos);
	ret = increment_y(&r);
	CU_ASSERT_DOUBLE_EQUAL(ret.x, -5, 0.0000000001);
	CU_ASSERT_DOUBLE_EQUAL(ret.y, 6, 0.0000000001);
	r.y_pos = ret;
	ret = increment_y(&r);
	CU_ASSERT_DOUBLE_EQUAL(ret.x, -9.0, 0.0000000001);
	CU_ASSERT_DOUBLE_EQUAL(ret.y, 7, 0.0000000001);
	r.y_pos = ret;
	ret = increment_y(&r);
	CU_ASSERT_DOUBLE_EQUAL(ret.x, -13, 0.0000000001);
	CU_ASSERT_DOUBLE_EQUAL(ret.y, 8, 0.0000000001);
}

void	test_inc_y_264(void)
{
	t_ray	r = {0};
	t_player p = {0};
	t_fpoint	ret;

	r.to_cast.radians = radian(264.2894068625);
	p.pos.y = 5;
	p.pos.x = 5;
	ray_set_incrementor(&r, r.to_cast.radians);
	rey_init(&r, r.to_cast.radians, p.pos);
	ret = increment_y(&r);
	CU_ASSERT_DOUBLE_EQUAL(ret.x, 4.9, 0.0000000001);
	CU_ASSERT_DOUBLE_EQUAL(ret.y, 4, 0.0000000001);
	r.y_pos = ret;
	ret = increment_y(&r);
	CU_ASSERT_DOUBLE_EQUAL(ret.x, 4.8, 0.0000000001);
	CU_ASSERT_DOUBLE_EQUAL(ret.y, 3, 0.0000000001);
	r.y_pos = ret;
	ret = increment_y(&r);
	CU_ASSERT_DOUBLE_EQUAL(ret.x, 4.7, 0.0000000001);
	CU_ASSERT_DOUBLE_EQUAL(ret.y, 2, 0.0000000001);
}

void	test_inc_y_288(void)
{
	t_ray	r = {0};
	t_player p = {0};
	t_fpoint	ret;

	r.to_cast.radians = radian(288.43494882292);
	p.pos.y = -1;
	p.pos.x = -6;
	ray_set_incrementor(&r, r.to_cast.radians);
	rey_init(&r, r.to_cast.radians, p.pos);
	ret = increment_y(&r);
	CU_ASSERT_DOUBLE_EQUAL(ret.x, -5.666666666666666, 0.00001);
	CU_ASSERT_DOUBLE_EQUAL(ret.y, -2, 0.0000000001);
	r.y_pos = ret;
	ret = increment_y(&r);
	CU_ASSERT_DOUBLE_EQUAL(ret.x, -5.33333333333333, 0.00001);
	CU_ASSERT_DOUBLE_EQUAL(ret.y, -3, 0.0000000001);
	r.y_pos = ret;
	ret = increment_y(&r);
	CU_ASSERT_DOUBLE_EQUAL(ret.x, -5, 0.0000000001);
	CU_ASSERT_DOUBLE_EQUAL(ret.y, -4, 0.0000000001);
}

void	test_ray_inc(void)
{
	test_inc_y_63();
	test_inc_y_165();
	test_inc_y_264();
	test_inc_y_288();
}
