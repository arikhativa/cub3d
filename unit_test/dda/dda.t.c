/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.t.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:21:17 by yoav              #+#    #+#             */
/*   Updated: 2023/04/12 12:14:00 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dda.h"
#include "unit_test.h"
#include "unit_test_util.h"

void	test_dda1(void)
{
	t_fpoint	start_pos = {0};
	t_ray	r;
	t_collinfo	collinfo;
	char **map = util_create_rev_map(2,
		"1",
		"N"
	);

	ft_bzero(&r, sizeof(t_ray));
	start_pos = fpoint_init(0.5, 0.5);
	r.to_cast = radian(90);
	dda(map, start_pos, &r, &collinfo);
	CU_ASSERT_DOUBLE_EQUAL(collinfo.collision.x, 0.5, 0.0000001);
	CU_ASSERT_DOUBLE_EQUAL(collinfo.collision.y, 1, 0.0000001);
	tab_deep_destroy(&map);
}

void	test_dda2(void)
{
	t_fpoint	start_pos = {0};
	t_ray	r;
	t_collinfo	collinfo;
	char **map = util_create_rev_map(
		3,
		"1",
		"0",
		"N"
	);

	ft_bzero(&r, sizeof(t_ray));
	start_pos = fpoint_init(0.5, 0.5);
	r.to_cast = radian(90);
	dda(map, start_pos, &r, &collinfo);
	CU_ASSERT_DOUBLE_EQUAL(collinfo.collision.x, 0.5, 0.0000001);
	CU_ASSERT_DOUBLE_EQUAL(collinfo.collision.y, 2, 0.0000001);
	tab_deep_destroy(&map);
}

void	test_dda3(void)
{
	t_fpoint	start_pos = {0};
	t_ray	r;
	t_collinfo	collinfo;
	char **map = util_create_rev_map(
		1,
		"W00101"
	);

	ft_bzero(&r, sizeof(t_ray));
	start_pos = fpoint_init(0.5, 0.5);
	r.to_cast = radian(0);
	dda(map, start_pos, &r, &collinfo);
	CU_ASSERT_DOUBLE_EQUAL(collinfo.collision.x, 3, 0.0000001);
	CU_ASSERT_DOUBLE_EQUAL(collinfo.collision.y, 0.5, 0.0000001);
	tab_deep_destroy(&map);
}

void	test_dda4(void)
{
	t_fpoint	start_pos = {0};
	t_ray	r;
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

	ft_bzero(&r, sizeof(t_ray));
	start_pos = fpoint_init(0.5, 7.5);
	r.to_cast = radian(-90);
	dda(map, start_pos, &r, &collinfo);
	CU_ASSERT_DOUBLE_EQUAL(collinfo.collision.x, 0.5, 0.0000001);
	CU_ASSERT_DOUBLE_EQUAL(collinfo.collision.y, 2, 0.0000001);
	tab_deep_destroy(&map);
}

void	test_dda_perfect_ne(void)
{
	t_fpoint	start_pos = {0};
	t_ray	r;
	t_collinfo	collinfo;
	char **map = util_create_rev_map(
		5,
		"11111",
		"10011",
		"10001",
		"1N001",
		"11111"
	);

	ft_bzero(&r, sizeof(t_ray));
	start_pos = fpoint_init(1.5, 1.5);
	r.to_cast = radian(45);
	dda(map, start_pos, &r, &collinfo);
	CU_ASSERT_DOUBLE_EQUAL(collinfo.collision.x, 3, 0.0000001);
	CU_ASSERT_DOUBLE_EQUAL(collinfo.collision.y, 3, 0.0000001);
	tab_deep_destroy(&map);
}

void	test_dda_perfect_nw(void)
{
	t_fpoint	start_pos = {0};
	t_ray	r;
	t_collinfo	collinfo;
	t_point	test = {0};
	char **map = util_create_rev_map(
		6,
		"111111",
		"110111",
		"100011",
		"110001",
		"1110N1",
		"111111"
	);

	ft_bzero(&r, sizeof(t_ray));
	start_pos = fpoint_init(4.5, 1.5);
	r.to_cast = radian(90 + 45);
	dda(map, start_pos, &r, &collinfo);
	test = fpoint_to_point(collinfo.collision);
	CU_ASSERT_EQUAL(test.x, 2);
	CU_ASSERT_EQUAL(test.y, 4);
	tab_deep_destroy(&map);
}

void	test_dda_perfect_se(void)
{
	t_fpoint	start_pos = {0};
	t_ray	r;
	t_point	test = {0};
	t_collinfo	collinfo;
	char **map = util_create_rev_map(
		7,
		"S01111",
		"000111",
		"100011",
		"110001",
		"111000",
		"1111000",
		"1111101"
	);

	ft_bzero(&r, sizeof(t_ray));
	start_pos = fpoint_init(0.5, 6.5);
	r.to_cast = radian(-45);
	dda(map, start_pos, &r, &collinfo);
	test = fpoint_to_point(collinfo.collision);
	CU_ASSERT_EQUAL(test.x, 6);
	CU_ASSERT_EQUAL(test.y, 1);
	tab_deep_destroy(&map);
}

void	test_dda_perfect_sw(void)
{
	t_fpoint	start_pos = {0};
	t_ray	r;
	t_point	test = {0};
	t_collinfo	collinfo;
	char **map = util_create_rev_map(
		13,
		"111111111110S1",
		"11111111110001",
		"1111111110001",
		"1111111100011",
		"111111100011",
		"11111100011",
		"1111100011",
		"111100011",
		"11100011",
		"1100011",
		"100011",
		"00011",
		"1011"
	);

	ft_bzero(&r, sizeof(t_ray));
	start_pos = fpoint_init(12.5, 12.5);
	r.to_cast = radian(180 + 45);
	dda(map, start_pos, &r, &collinfo);
	test = fpoint_to_point(collinfo.collision);
	CU_ASSERT_EQUAL(test.x, 1);
	CU_ASSERT_EQUAL(test.y, 1);
	tab_deep_destroy(&map);
}

void	test_dda_degree_63(void)
{
	t_fpoint	start_pos = {0};
	t_ray	r;
	t_collinfo	collinfo;
	char **map = util_create_rev_map(
		8,
		"11111111",
		"11010111",
		"11001111",
		"11011111",
		"10011111",
		"10111111",
		"00111111",
		"N1111111"
	);

	ft_bzero(&r, sizeof(t_ray));
	start_pos = fpoint_init(0.5, 0.5);
	r.to_cast = radian(63.434948822922);
	dda(map, start_pos, &r, &collinfo);
	CU_ASSERT_DOUBLE_EQUAL(collinfo.collision.x, 3.25, 0.0000001);
	CU_ASSERT_DOUBLE_EQUAL(collinfo.collision.y, 6, 0.0000001);

	tab_deep_destroy(&map);
}

// TODO this test is depended on the bug "DDA issue #61"
void	test_dda_degree_104(void)
{
	t_fpoint	start_pos = {0};
	t_ray	r;
	t_collinfo collinfo;
	char **map = util_create_rev_map(
		5,
		"111111",
		"100111",
		"100101",
		"100111",
		"01N101"
	);

	ft_bzero(&r, sizeof(t_ray));
	start_pos = fpoint_init(2.5, 0.5);
	r.to_cast = radian(104.03624346793);
	dda(map, start_pos, &r, &collinfo);
	CU_ASSERT_DOUBLE_EQUAL(collinfo.collision.x, 1.625, 0.000001);
	CU_ASSERT_DOUBLE_EQUAL(collinfo.collision.y, 4, 0.000001);
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
	test_dda_degree_104();
}