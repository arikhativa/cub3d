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

void	test_inc_x_63(void)
{
	t_ray	r = {0};
	t_fpoint p = {0};
	t_fpoint	ret;

	r.to_cast.radians = radian(63.434948822922);
	p.y = 2.5;
	p.x = 10;
	ray_set_incrementor(&r, r.to_cast.radians);
	rey_init(&r, r.to_cast.radians, p);

	ret = ray_get_next_x(&r);
	CU_ASSERT_DOUBLE_EQUAL(ret.x, 11, 0.0000000001);
	CU_ASSERT_DOUBLE_EQUAL(ret.y, 4.5, 0.0000000001);
	r.x_pos = ret;
	ret = ray_get_next_x(&r);
	CU_ASSERT_DOUBLE_EQUAL(ret.x, 12, 0.0000000001);
	CU_ASSERT_DOUBLE_EQUAL(ret.y, 6.5, 0.0000000001);
	r.x_pos = ret;
	ret = ray_get_next_x(&r);
	CU_ASSERT_DOUBLE_EQUAL(ret.x, 13, 0.0000000001);
	CU_ASSERT_DOUBLE_EQUAL(ret.y, 8.5, 0.0000000001);
}

void	test_inc_x_165(void)
{
	t_ray	r = {0};
	t_fpoint p = {0};
	t_fpoint	ret;

	r.to_cast.radians = radian(165.96375653207);
	p.x = -1;
	p.y = 5;
	ray_set_incrementor(&r, r.to_cast.radians);
	rey_init(&r, r.to_cast.radians, p);
	ret = ray_get_next_x(&r);
	CU_ASSERT_DOUBLE_EQUAL(ret.x, -2, 0.0000000001);
	CU_ASSERT_DOUBLE_EQUAL(ret.y, 5.25, 0.0000000001);
	r.x_pos = ret;
	ret = ray_get_next_x(&r);
	CU_ASSERT_DOUBLE_EQUAL(ret.x, -3, 0.0000000001);
	CU_ASSERT_DOUBLE_EQUAL(ret.y, 5.5, 0.0000000001);
	r.x_pos = ret;
	ret = ray_get_next_x(&r);
	CU_ASSERT_DOUBLE_EQUAL(ret.x, -4, 0.0000000001);
	CU_ASSERT_DOUBLE_EQUAL(ret.y, 5.75, 0.0000000001);
}

void	test_inc_x_264(void)
{
	t_ray	r = {0};
	t_fpoint p = {0};
	t_fpoint	ret;

	r.to_cast.radians = radian(264.2894068625);
	p.x = 5;
	p.y = 5;
	ray_set_incrementor(&r, r.to_cast.radians);
	rey_init(&r, r.to_cast.radians, p);
	ret = ray_get_next_x(&r);
	CU_ASSERT_DOUBLE_EQUAL(ret.x, 4, 0.0000000001);
	CU_ASSERT_DOUBLE_EQUAL(ret.y, -5, 0.0000000001);
	r.x_pos = ret;
	ret = ray_get_next_x(&r);
	CU_ASSERT_DOUBLE_EQUAL(ret.x, 3, 0.0000000001);
	CU_ASSERT_DOUBLE_EQUAL(ret.y, -15, 0.0000000001);
	r.x_pos = ret;
	ret = ray_get_next_x(&r);
	CU_ASSERT_DOUBLE_EQUAL(ret.x, 2, 0.0000000001);
	CU_ASSERT_DOUBLE_EQUAL(ret.y, -25, 0.0000000001);
}

void	test_inc_x_288(void)
{
	t_ray	r = {0};
	t_fpoint p = {0};
	t_fpoint	ret;

	r.to_cast.radians = radian(288.43494882292);
	p.x = -6;
	p.y = -1;
	ray_set_incrementor(&r, r.to_cast.radians);
	rey_init(&r, r.to_cast.radians, p);
	ret = ray_get_next_x(&r);
	CU_ASSERT_DOUBLE_EQUAL(ret.x, -5, 0.00001);
	CU_ASSERT_DOUBLE_EQUAL(ret.y, -4, 0.0000000001);
	r.x_pos = ret;
	ret = ray_get_next_x(&r);
	CU_ASSERT_DOUBLE_EQUAL(ret.x, -4, 0.00001);
	CU_ASSERT_DOUBLE_EQUAL(ret.y, -7, 0.0000000001);
	r.x_pos = ret;
	ret = ray_get_next_x(&r);
	CU_ASSERT_DOUBLE_EQUAL(ret.x, -3, 0.0000000001);
	CU_ASSERT_DOUBLE_EQUAL(ret.y, -10, 0.0000000001);
}

void	test_ray_inc_x(void)
{
	test_inc_x_63();
	test_inc_x_165();
	test_inc_x_264();
	test_inc_x_288();
}