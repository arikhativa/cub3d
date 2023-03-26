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

void	test_dda_set_incrementor(void)
{
	t_ray	r = {0};
	double	rad = radian(0);
	
	dda_set_incrementor(&r, rad);
	CU_ASSERT_EQUAL(r.incrementor.x, 1);
	CU_ASSERT_EQUAL(r.incrementor.y, 0);

	rad = radian(45);
	dda_set_incrementor(&r, rad);
	CU_ASSERT_EQUAL(r.incrementor.x, 1);
	CU_ASSERT_EQUAL(r.incrementor.y, 1);

	rad = radian(90);
	dda_set_incrementor(&r, rad);
	CU_ASSERT_EQUAL(r.incrementor.x, 0);
	CU_ASSERT_EQUAL(r.incrementor.y, 1);

	rad = radian(135);
	dda_set_incrementor(&r, rad);
	CU_ASSERT_EQUAL(r.incrementor.x, -1);
	CU_ASSERT_EQUAL(r.incrementor.y, 1);

	rad = radian(180);
	dda_set_incrementor(&r, rad);
	CU_ASSERT_EQUAL(r.incrementor.x, -1);
	CU_ASSERT_EQUAL(r.incrementor.y, 0);

	rad = radian(180 + 45);
	dda_set_incrementor(&r, rad);
	CU_ASSERT_EQUAL(r.incrementor.x, -1);
	CU_ASSERT_EQUAL(r.incrementor.y, -1);

	rad = radian(270);
	dda_set_incrementor(&r, rad);
	CU_ASSERT_EQUAL(r.incrementor.x, 0);
	CU_ASSERT_EQUAL(r.incrementor.y, -1);

	rad = radian(270 + 45);
	dda_set_incrementor(&r, rad);
	CU_ASSERT_EQUAL(r.incrementor.x, 1);
	CU_ASSERT_EQUAL(r.incrementor.y, -1);

	rad = radian(360);
	dda_set_incrementor(&r, rad);
	CU_ASSERT_EQUAL(r.incrementor.x, 1);
	CU_ASSERT_EQUAL(r.incrementor.y, 0);

	rad = radian(360 + 1);
	dda_set_incrementor(&r, rad);
	CU_ASSERT_EQUAL(r.incrementor.x, 1);
	CU_ASSERT_EQUAL(r.incrementor.y, 1);

	rad = radian(-1);
	dda_set_incrementor(&r, rad);
	CU_ASSERT_EQUAL(r.incrementor.x, 1);
	CU_ASSERT_EQUAL(r.incrementor.y, -1);
}


void	test_dda1(void)
{
	t_player	p = {0};
	t_ray	r = {0};
	t_fpoint	collision = {0};
	char **map = util_create_rev_map(2,
		"1",
		"N"
	);

	p.pos = point_init(0, 0);
	r.to_cast.radians = radian(90);
	dda(map, &p, &r, &collision);
	CU_ASSERT_EQUAL(collision.x, 0);
	CU_ASSERT_EQUAL(collision.y, 1);
	tab_deep_destroy(&map);
}

void	test_dda2(void)
{
	t_player	p = {0};
	t_ray	r = {0};
	t_fpoint	collision = {0};
	char **map = util_create_rev_map(2,
		"1",
		"0",
		"N"
	);

	p.pos = point_init(0, 0);
	r.to_cast.radians = radian(90);
	collision = fpoint_init(0, 0);
	dda(map, &p, &r, &collision);
	CU_ASSERT_EQUAL(collision.x, 0);
	CU_ASSERT_EQUAL(collision.y, 2);
	fpoint_print(collision);
	tab_deep_destroy(&map);
}

void	test_dda(void)
{
	// test_dda1();
	test_dda2();
}
