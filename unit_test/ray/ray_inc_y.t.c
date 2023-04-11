/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_inc_y.t.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:21:17 by yoav              #+#    #+#             */
/*   Updated: 2023/04/11 16:02:05 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "unit_test.h"

void	test_inc_y_63(void)
{
	t_ray	r;
	t_fpoint p = {0};
	t_fpoint	ret;

	r.to_cast = radian(63.434948822922);
	p.y = 2.5;
	p.x = 10.5;
	ray_set_incrementor(&r, r.to_cast);
	rey_init(&r, r.to_cast, p);

	ret = ray_get_next_y(&r);
	CU_ASSERT_DOUBLE_EQUAL(ret.x, 10.75, 0.0000000001);
	CU_ASSERT_DOUBLE_EQUAL(ret.y, 3, 0.0000000001);
	r.y_pos = ret;
	ret = ray_get_next_y(&r);
	CU_ASSERT_DOUBLE_EQUAL(ret.x, 11.25, 0.0000000001);
	CU_ASSERT_DOUBLE_EQUAL(ret.y, 4, 0.0000000001);
	r.y_pos = ret;
	ret = ray_get_next_y(&r);
	CU_ASSERT_DOUBLE_EQUAL(ret.x, 11.75, 0.0000000001);
	CU_ASSERT_DOUBLE_EQUAL(ret.y, 5, 0.0000000001);
}

void	test_inc_y_165(void)
{
	t_ray	r;
	t_fpoint p = {0};
	t_fpoint	ret;

	r.to_cast = radian(165.96375653207);
	p.y = 5;
	p.x = -1;
	ray_set_incrementor(&r, r.to_cast);
	rey_init(&r, r.to_cast, p);
	ret = ray_get_next_y(&r);
	CU_ASSERT_DOUBLE_EQUAL(ret.x, -5, 0.0000000001);
	CU_ASSERT_DOUBLE_EQUAL(ret.y, 6, 0.0000000001);
	r.y_pos = ret;
	ret = ray_get_next_y(&r);
	CU_ASSERT_DOUBLE_EQUAL(ret.x, -9.0, 0.0000000001);
	CU_ASSERT_DOUBLE_EQUAL(ret.y, 7, 0.0000000001);
	r.y_pos = ret;
	ret = ray_get_next_y(&r);
	CU_ASSERT_DOUBLE_EQUAL(ret.x, -13, 0.0000000001);
	CU_ASSERT_DOUBLE_EQUAL(ret.y, 8, 0.0000000001);
}

void	test_inc_y_264(void)
{
	t_ray	r;
	t_fpoint p = {0};
	t_fpoint	ret;

	r.to_cast = radian(264.2894068625);
	p.y = 5;
	p.x = 5;
	ray_set_incrementor(&r, r.to_cast);
	rey_init(&r, r.to_cast, p);
	ret = ray_get_next_y(&r);
	CU_ASSERT_DOUBLE_EQUAL(ret.x, 4.9, 0.0000000001);
	CU_ASSERT_DOUBLE_EQUAL(ret.y, 4, 0.0000000001);
	r.y_pos = ret;
	ret = ray_get_next_y(&r);
	CU_ASSERT_DOUBLE_EQUAL(ret.x, 4.8, 0.0000000001);
	CU_ASSERT_DOUBLE_EQUAL(ret.y, 3, 0.0000000001);
	r.y_pos = ret;
	ret = ray_get_next_y(&r);
	CU_ASSERT_DOUBLE_EQUAL(ret.x, 4.7, 0.0000000001);
	CU_ASSERT_DOUBLE_EQUAL(ret.y, 2, 0.0000000001);
}

void	test_inc_y_288(void)
{
	t_ray	r;
	t_fpoint p = {0};
	t_fpoint	ret;

	r.to_cast = radian(288.43494882292);
	p.y = -1;
	p.x = -6;
	ray_set_incrementor(&r, r.to_cast);
	rey_init(&r, r.to_cast, p);
	ret = ray_get_next_y(&r);
	CU_ASSERT_DOUBLE_EQUAL(ret.x, -5.666666666666666, 0.00001);
	CU_ASSERT_DOUBLE_EQUAL(ret.y, -2, 0.0000000001);
	r.y_pos = ret;
	ret = ray_get_next_y(&r);
	CU_ASSERT_DOUBLE_EQUAL(ret.x, -5.33333333333333, 0.00001);
	CU_ASSERT_DOUBLE_EQUAL(ret.y, -3, 0.0000000001);
	r.y_pos = ret;
	ret = ray_get_next_y(&r);
	CU_ASSERT_DOUBLE_EQUAL(ret.x, -5, 0.0000000001);
	CU_ASSERT_DOUBLE_EQUAL(ret.y, -4, 0.0000000001);
}

void	test_ray_inc_y(void)
{
	test_inc_y_63();
	test_inc_y_165();
	test_inc_y_264();
	test_inc_y_288();
}