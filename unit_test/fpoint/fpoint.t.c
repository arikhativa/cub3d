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

#include "fpoint.h"
#include "unit_test.h"

void	test_fpoint(void)
{
	t_fpoint	p1;
	t_fpoint	p2;

	p1 = fpoint_init(1.1, 2.2);
	p2 = fpoint_copy(p1);
	CU_ASSERT_EQUAL(p1.x, 1.1);
	CU_ASSERT_EQUAL(p1.y, 2.2);
	CU_ASSERT_EQUAL(p1.x, p2.x);
	CU_ASSERT_EQUAL(p1.y, p2.y);
}

void	test_fpoint_init(void)
{
	t_fpoint		p;

	p = fpoint_init(5.5, 6.5);
	CU_ASSERT_EQUAL(5.5, p.x);
	CU_ASSERT_EQUAL(6.5, p.y);
}

void	test_fpoint_to_point(void)
{
	t_fpoint		fp;
	t_point			p;

	fp = fpoint_init(5.8, 6.99);
	p = fpoint_to_point(fp);
	CU_ASSERT_EQUAL(5, p.x);
	CU_ASSERT_EQUAL(6, p.y);	
}

void	test_point_to_fpoint(void)
{
	t_fpoint		p;
	t_point			p2;

	p2 = point_init(5, 6);
	p = point_to_fpoint(p2);
	CU_ASSERT_EQUAL(5.0, p.x);
	CU_ASSERT_EQUAL(6.0, p.y);	
}

void	test_small_round_up(void)
{
	t_fpoint	fp;
	t_point		p;
	fp = fpoint_init(0, 2.999999999999999);
	p = fpoint_to_point(fp);
	CU_ASSERT_EQUAL(p.x, 0);
	CU_ASSERT_EQUAL(p.y, 3);
}

void test_fpoint_get_distance()
{
	t_fpoint	p1;
	t_fpoint	p2;
	double		distance;

	p1 = fpoint_init(0, 0);
	p2 = fpoint_init(3, 4);
	distance = fpoint_get_distance(p1, p2);
	CU_ASSERT_EQUAL(distance, 5);

	p1 = fpoint_init(0, 0);
	p2 = fpoint_init(0, 1);
	distance = fpoint_get_distance(p1, p2);
	CU_ASSERT_EQUAL(distance, 1);

	p1 = fpoint_init(-1, 0);
	p2 = fpoint_init(0, 0);
	distance = fpoint_get_distance(p1, p2);
	CU_ASSERT_EQUAL(distance, 1);

	p1 = fpoint_init(3, 2);
	p2 = fpoint_init(9, 7);
	distance = fpoint_get_distance(p1, p2);
	CU_ASSERT_DOUBLE_EQUAL(distance, 7.810250, 0.000001);

	p1 = fpoint_init(-5.5, 20.3);
	p2 = fpoint_init(93.4, 1.7);
	distance = fpoint_get_distance(p1, p2);
	CU_ASSERT_DOUBLE_EQUAL(distance, 100.6338412265, 0.000001);
}
