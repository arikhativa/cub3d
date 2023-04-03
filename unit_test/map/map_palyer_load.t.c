/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.t.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:21:17 by yoav              #+#    #+#             */
/*   Updated: 2023/02/15 14:02:49 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "unit_test.h"

void	test_map_load_player(void)
{
	t_error_code	err;
	t_map			*m;
	char *map[] = {
		" 1111",
		"10N1",
		"1001",
		"1111",
		NULL,
	};

	err = map_create(&m);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	m->map = map;
	m->size = point_init(5, 4);
	err = map_load_player(m);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	CU_ASSERT_EQUAL(m->p->dir, NORTH);
	CU_ASSERT_DOUBLE_EQUAL(m->p->pos.x, 2.5, 0.00001);
	CU_ASSERT_DOUBLE_EQUAL(m->p->pos.y, 1.5, 0.00001);
	m->map = NULL;
	map_destroy(&m);
}

void	test_map_load_player_err_no_player(void)
{
	t_error_code	err;
	t_map			*m;
	char *map[] = {
		" 1111",
		"1001",
		"1001",
		"1111",
		NULL,
	};

	err = map_create(&m);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	m->map = map;
	m->size = point_init(5, 4);
	err = map_load_player(m);
	CU_ASSERT_EQUAL(EXT_MISSING_PLAYER, err);
	m->map = NULL;
	map_destroy(&m);
}

void	test_map_load_player_err_dup_player(void)
{
	t_error_code	err;
	t_map			*m;
	char *map[] = {
		" 1111",
		"1SS1",
		"1001",
		"1111",
		NULL,
	};

	err = map_create(&m);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	m->map = map;
	m->size = point_init(5, 4);
	err = map_load_player(m);
	CU_ASSERT_EQUAL(EXT_DUPLICATE_SETTING, err);
	m->map = NULL;
	map_destroy(&m);
}
