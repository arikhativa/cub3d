/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.t.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:47:50 by yrabby            #+#    #+#             */
/*   Updated: 2023/02/15 13:48:02 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "unit_test.h"

static char *g_map[] = {
	"11111111",
	"10000001",
	"10000001",
	"10000001",
	"10000001",
	"11111111"
};

void	test_player_move_forward(void)
{
	t_player	p;

	p.dir = radian(0);
	p.pos = fpoint_init(2, 3);
	player_move_forward(&p, g_map);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.x, 3, 0.00001);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.y, 3, 0.00001);

	p.dir = radian(45);
	p.pos = fpoint_init(2, 3);
	player_move_forward(&p, g_map);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.x, 2.707107, 0.00001);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.y, 3.707107, 0.00001);

	p.dir = radian(90);
	p.pos = fpoint_init(2, 3);
	player_move_forward(&p, g_map);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.x, 2, 0.00001);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.y, 4, 0.00001);

	p.dir = radian(180);
	p.pos = fpoint_init(2, 3);
	player_move_forward(&p, g_map);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.x, 1, 0.00001);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.y, 3, 0.00001);

	p.dir = radian(-90);
	p.pos = fpoint_init(2, 3);
	player_move_forward(&p, g_map);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.x, 2, 0.00001);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.y, 2, 0.00001);
}

void	test_player_move_backward(void)
{
	t_player	p;

	p.dir = radian(0);
	p.pos = fpoint_init(2, 3);
	player_move_backward(&p, g_map);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.x, 1, 0.00001);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.y, 3, 0.00001);

	p.dir = radian(45);
	p.pos = fpoint_init(2, 3);
	player_move_backward(&p, g_map);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.x, 2.0 - .707107, 0.00001);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.y, 3.0 - .707107, 0.00001);

	p.dir = radian(90);
	p.pos = fpoint_init(2, 3);
	player_move_backward(&p, g_map);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.x, 2, 0.00001);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.y, 2, 0.00001);

	p.dir = radian(180);
	p.pos = fpoint_init(2, 3);
	player_move_backward(&p, g_map);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.x, 3, 0.00001);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.y, 3, 0.00001);

	p.dir = radian(-90);
	p.pos = fpoint_init(2, 3);
	player_move_backward(&p, g_map);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.x, 2, 0.00001);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.y, 4, 0.00001);
}

void	test_player_move_left(void)
{
	t_player	p;

	p.dir = radian(0);
	p.pos = fpoint_init(2, 3);
	player_move_left(&p, g_map);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.x, 2, 0.00001);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.y, 4, 0.00001);

	p.dir = radian(45);
	p.pos = fpoint_init(2, 3);
	player_move_left(&p, g_map);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.x, 2 - .707107, 0.00001);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.y, 3 + .707107, 0.00001);

	p.dir = radian(90);
	p.pos = fpoint_init(2, 3);
	player_move_left(&p, g_map);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.x, 1, 0.00001);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.y, 3, 0.00001);

	p.dir = radian(180);
	p.pos = fpoint_init(2, 3);
	player_move_left(&p, g_map);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.x, 2, 0.00001);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.y, 2, 0.00001);

	p.dir = radian(-90);
	p.pos = fpoint_init(2, 3);
	player_move_left(&p, g_map);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.x, 3, 0.00001);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.y, 3, 0.00001);
}

void	test_player_move(void)
{
	test_player_move_forward();
	test_player_move_backward();
	test_player_move_left();
}