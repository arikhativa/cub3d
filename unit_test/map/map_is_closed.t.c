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
#include "unit_test_util.h"

void	test_map_is_closed(void)
{
	t_bool	is_closed;
	t_error_code	err;
	t_map			*m;
	char **map = util_create_tab(5,
		"11111",
		"10001",
		"10N01",
		"10001",
		"11111"
	);

	err = map_create(&m, g_mlx);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	m->map = map;
	m->size = point_init(5, 5);
	err = map_load_player(m);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	is_closed = map_is_closed(m);
	CU_ASSERT_EQUAL(TRUE, is_closed);
	map_destroy(&m);
}

void	test_map_is_closed_err1(void)
{
	t_bool	is_closed;
	t_error_code	err;
	t_map			*m;
	char **map = util_create_tab(5,
		"11111",
		"10001",
		"10N00",
		"10001",
		"11111"
	);

	err = map_create(&m, g_mlx);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	m->map = map;
	m->size = point_init(6, 5);
	err = map_load_player(m);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	is_closed = map_is_closed(m);
	CU_ASSERT_EQUAL(FALSE, is_closed);
	map_destroy(&m);
}

void	test_map_is_closed_err2(void)
{
	t_bool	is_closed;
	t_error_code	err;
	t_map			*m;
	char **map = util_create_tab(5,
		"11111",
		"10001",
		"10N0 ",
		"10001",
		"11111"
	);

	err = map_create(&m, g_mlx);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	m->map = map;
	m->size = point_init(6, 5);
	err = map_load_player(m);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	is_closed = map_is_closed(m);
	CU_ASSERT_EQUAL(FALSE, is_closed);
	map_destroy(&m);
}
