/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.t.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:21:17 by yoav              #+#    #+#             */
/*   Updated: 2023/03/30 13:13:04 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dda.h"
#include "unit_test.h"
#include "unit_test_util.h"

void	test_dda1(void)
{
	t_player	p = {0};
	t_ray	r = {0};
	t_collinfo	collinfo;
	char **map = util_create_rev_map(2,
		"1",
		"N"
	);

	p.pos = point_init(0, 0);
	r.to_cast.radians = radian(90);
	dda(map, &p, &r, &collinfo);
	CU_ASSERT_EQUAL(collinfo.collision.x, 0);
	CU_ASSERT_EQUAL(collinfo.collision.y, 1);
	tab_deep_destroy(&map);
}

void	test_dda2(void)
{
	t_player	p = {0};
	t_ray	r = {0};
	t_collinfo	collinfo;
	char **map = util_create_rev_map(
		3,
		"1",
		"0",
		"N"
	);

	p.pos = point_init(0, 0);
	r.to_cast.radians = radian(90);
	dda(map, &p, &r, &collinfo);
	CU_ASSERT_EQUAL(collinfo.collision.x, 0);
	CU_ASSERT_EQUAL(collinfo.collision.y, 2);
	tab_deep_destroy(&map);
}

void	test_dda3(void)
{
	t_player	p = {0};
	t_ray	r = {0};
	t_collinfo	collinfo;
	char **map = util_create_rev_map(
		1,
		"W00101"
	);

	p.pos = point_init(0, 0);
	r.to_cast.radians = radian(0);
	dda(map, &p, &r, &collinfo);
	CU_ASSERT_EQUAL(collinfo.collision.x, 3);
	CU_ASSERT_EQUAL(collinfo.collision.y, 0);
	tab_deep_destroy(&map);
}

void	test_dda4(void)
{
	t_player	p = {0};
	t_ray	r = {0};
	t_collinfo	collinfo;
	char **map = util_create_rev_map(
		8,
		"S",
		"0",
		"0",
		"0",
		"0",
		"0",
		"1",
		"1"
	);

	p.pos = point_init(0, 7);
	r.to_cast.radians = radian(-90);
	dda(map, &p, &r, &collinfo);
	CU_ASSERT_EQUAL(collinfo.collision.x, 0);
	CU_ASSERT_EQUAL(collinfo.collision.y, 1);
	tab_deep_destroy(&map);
}

void	test_dda_perfect_ne(void)
{
	t_player	p = {0};
	t_ray	r = {0};
	t_collinfo	collinfo;
	char **map = util_create_rev_map(
		5,
		"11111",
		"10011",
		"10001",
		"1S001",
		"11111"
	);

	p.pos = point_init(1, 1);
	r.to_cast.radians = radian(45);
	dda(map, &p, &r, &collinfo);
	CU_ASSERT_EQUAL(collinfo.collision.x, 3);
	CU_ASSERT_EQUAL(collinfo.collision.y, 3);
	tab_deep_destroy(&map);
}

void	test_dda_perfect_nw(void)
{
	t_player	p = {0};
	t_ray	r = {0};
	t_collinfo	collinfo;
	t_point	test = {0};
	char **map = util_create_rev_map(
		6,
		"111111",
		"111111",
		"110111",
		"111011",
		"1111N1",
		"111111"
	);

	p.pos = point_init(4, 1);
	r.to_cast.radians = radian(90 + 45);
	dda(map, &p, &r, &collinfo);
	test = fpoint_to_point(collinfo.collision);
	CU_ASSERT_EQUAL(test.x, 1);
	CU_ASSERT_EQUAL(test.y, 4);
	tab_deep_destroy(&map);
}

void	test_dda_perfect_se(void)
{
	t_player	p = {0};
	t_ray	r = {0};
	t_point	test = {0};
	t_collinfo	collinfo;
	char **map = util_create_rev_map(
		7,
		"S11111",
		"101111",
		"110111",
		"111011",
		"111101",
		"1111101",
		"1111111"
	);

	p.pos = point_init(0, 6);
	r.to_cast.radians = radian(-45);
	dda(map, &p, &r, &collinfo);
	test = fpoint_to_point(collinfo.collision);
	CU_ASSERT_EQUAL(test.x, 6);
	CU_ASSERT_EQUAL(test.y, 0);
	tab_deep_destroy(&map);
}

void	test_dda_perfect_sw(void)
{
	t_player	p = {0};
	t_ray	r = {0};
	t_point	test = {0};
	t_collinfo	collinfo;
	char **map = util_create_rev_map(
		13,
		"111111111111S",
		"1111111111101",
		"1111111111011",
		"1111111110111",
		"111111110111",
		"11111110111",
		"1111110111",
		"111110111",
		"11110111",
		"1110111",
		"110111",
		"10111",
		"1111"
	);

	p.pos = point_init(12, 12);
	r.to_cast.radians = radian(180 + 45);
	dda(map, &p, &r, &collinfo);
	test = fpoint_to_point(collinfo.collision);
	CU_ASSERT_EQUAL(test.x, 0);
	CU_ASSERT_EQUAL(test.y, 0);
	tab_deep_destroy(&map);
}

void	test_dda_degree_63(void)
{
	t_player	p = {0};
	t_ray	r = {0};
	t_point	test = {0};
	t_collinfo	collinfo;
	char **map = util_create_rev_map(
		7,
		"11111111",
		"11010001",
		"11010001",
		"10100011",
		"10101111",
		"01011111",
		"N1111111"
	);

	p.pos = point_init(0, 0);
	r.to_cast.radians = radian(63.434948822922);
	dda(map, &p, &r, &collinfo);
	test = fpoint_to_point(collinfo.collision);
	point_print(test); printf("\n");
	CU_ASSERT_EQUAL(test.x, 3);
	CU_ASSERT_EQUAL(test.y, 6);
	tab_deep_destroy(&map);
}

void	test_dda(void)
{
	test_dda1();
	test_dda2();
	test_dda3();
	test_dda4();
	test_dda_perfect_ne();
	test_dda_perfect_nw();
	test_dda_perfect_se();
	test_dda_perfect_sw();
	test_dda_degree_63();
}