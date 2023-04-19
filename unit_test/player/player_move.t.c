/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.t.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:47:50 by yrabby            #+#    #+#             */
/*   Updated: 2023/04/19 12:03:10 by ycarro           ###   ########.fr       */
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
	p.pos = fpoint_init(2.1, 3.1);
	player_move_forward(&p, g_map);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.x, 3.1, 0.00001);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.y, 3.1, 0.00001);

	p.dir = radian(45);
	p.pos = fpoint_init(2, 3);
	player_move_forward(&p, g_map);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.x, 2.707107, 0.00001);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.y, 3.707107, 0.00001);

	p.dir = radian(90);
	p.pos = fpoint_init(2.1, 3.1);
	player_move_forward(&p, g_map);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.x, 2.1, 0.00001);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.y, 4.1, 0.00001);

	p.dir = radian(180);
	p.pos = fpoint_init(2.1, 3.1);
	player_move_forward(&p, g_map);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.x, 1.1, 0.00001);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.y, 3.1, 0.00001);

	p.dir = radian(-90);
	p.pos = fpoint_init(2.1, 3);
	player_move_forward(&p, g_map);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.x, 2.1, 0.00001);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.y, 2.1, 0.00001);
}

void	test_player_move_backward(void)
{
	t_player	p;

	p.dir = radian(0);
	p.pos = fpoint_init(2.1, 3.1);
	player_move_backward(&p, g_map);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.x, 1.1, 0.00001);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.y, 3.1, 0.00001);

	p.dir = radian(45);
	p.pos = fpoint_init(2.1, 3.1);
	player_move_backward(&p, g_map);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.x, 2.1 - .707107, 0.00001);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.y, 3.1 - .707107, 0.00001);

	p.dir = radian(90);
	p.pos = fpoint_init(2.1, 3.1);
	player_move_backward(&p, g_map);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.x, 2.1, 0.00001);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.y, 2.1, 0.00001);

	p.dir = radian(180);
	p.pos = fpoint_init(2, 3.1);
	player_move_backward(&p, g_map);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.x, 2.9, 0.00001);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.y, 3.1, 0.00001);

	p.dir = radian(-90);
	p.pos = fpoint_init(2.1, 3.1);
	player_move_backward(&p, g_map);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.x, 2.1, 0.00001);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.y, 4.1, 0.00001);
}

void	test_player_move_left(void)
{
	t_player	p;

	p.dir = radian(0);
	p.pos = fpoint_init(2.1, 3.1);
	player_move_left(&p, g_map);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.x, 2.1, 0.00001);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.y, 4.1, 0.00001);

	p.dir = radian(45);
	p.pos = fpoint_init(2.1, 3.1);
	player_move_left(&p, g_map);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.x, 2.1 - .707107, 0.00001);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.y, 3.1 + .707107, 0.00001);

	p.dir = radian(90);
	p.pos = fpoint_init(2.1, 3.1);
	player_move_left(&p, g_map);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.x, 1.1, 0.00001);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.y, 3.1, 0.00001);

	p.dir = radian(180);
	p.pos = fpoint_init(2.1, 3.1);
	player_move_left(&p, g_map);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.x, 2.1, 0.00001);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.y, 2.1, 0.00001);

	p.dir = radian(-90);
	p.pos = fpoint_init(2.1, 3.1);
	player_move_left(&p, g_map);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.x, 3.1, 0.00001);
	CU_ASSERT_DOUBLE_EQUAL(p.pos.y, 3.1, 0.00001);
}

void	test_player_move(void)
{
	test_player_move_forward();
	test_player_move_backward();
	test_player_move_left();
}