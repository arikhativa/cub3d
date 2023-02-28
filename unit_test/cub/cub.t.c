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

#include "cub.h"
#include "unit_test.h"

void	test_cub_get_line_type(void)
{
	t_line_type	type = cub_get_line_type("SO /path");
	CU_ASSERT_EQUAL(type, LINE_TYPE_SOUTH);
	type = cub_get_line_type("bad line");
	CU_ASSERT_EQUAL(type, LINE_TYPE_INVALID);
	type = cub_get_line_type("   0  0 1 1 N");
	CU_ASSERT_EQUAL(type, LINE_TYPE_MAP);
	type = cub_get_line_type("C 100,23,0");
	CU_ASSERT_EQUAL(type, LINE_TYPE_CEILING);
}

void	test_cub_get_dir(void)
{
	t_direction	d;

	d = cub_get_direction(NORTH_STR);
	CU_ASSERT_EQUAL(d, NORTH);
	d = cub_get_direction(WEST_STR);
	CU_ASSERT_EQUAL(d, WEST);
	d = cub_get_direction(SOUTH_STR);
	CU_ASSERT_EQUAL(d, SOUTH);
	d = cub_get_direction(WEST_STR);
	CU_ASSERT_EQUAL(d, WEST);
	d = cub_get_direction("asd");
	CU_ASSERT_EQUAL(d, DIR_INVALID);
}

void	test_cub_get_plane_type(void)
{
	t_plane_type	p;

	p = cub_get_plane_type(CEILING_STR);
	CU_ASSERT_EQUAL(p, PLANE_TYPE_CEILING);
	p = cub_get_plane_type(FLOOR_STR);
	CU_ASSERT_EQUAL(p, PLANE_TYPE_FLOOR);
	p = cub_get_plane_type("asd");
	CU_ASSERT_EQUAL(p, PLANE_TYPE_ERROR);
}

void	test_cub_get_rgb(void)
{
	t_rgb	rgb;

	rgb = cub_get_rgb("C 100,23,0");
	CU_ASSERT_EQUAL(rgb.red, 100);
	CU_ASSERT_EQUAL(rgb.blue, 23);
	CU_ASSERT_EQUAL(rgb.green, 0);
}
