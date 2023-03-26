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
