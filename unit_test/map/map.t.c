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

void	test_map_create_destroy(void)
{
	t_error_code	err;
	t_map			*obj;

	err = map_create(&obj);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	map_destroy(&obj);
	CU_ASSERT_PTR_NULL(obj);
}

void	test_map_get_map_index(void)
{
	int	i = 0;
	char *file[] = {
		"NO ./resource/xpm/wall.xpm",
		"SO ./resource/xpm/wall.xpm",
		"WE ./resource/xpm/wall.xpm",
		"EA ./resource/xpm/wall.xpm",
		"F 100,23,0",
		"",
		"C 100,23,0",
		" 1111",
		"10N1",
		"1  1",
		"1111",
		NULL,
	};

	i = map_get_map_index(file);
	CU_ASSERT_EQUAL(7, i);
}

void	test_map_get_size(void)
{
	t_error_code	err;
	t_map			*m;
	char *file[] = {
		"NO ./resource/xpm/wall.xpm",
		"SO ./resource/xpm/wall.xpm",
		"WE ./resource/xpm/wall.xpm",
		"EA ./resource/xpm/wall.xpm",
		"F 100,23,0",
		"",
		"C 100,23,0",
		" 1111",
		"10N1",
		"1  1",
		"1111",
		NULL,
	};

	err = map_create(&m);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	m->file = file;
	map_get_size(m);
	CU_ASSERT_EQUAL(m->size.x, 5);
	CU_ASSERT_EQUAL(m->size.y, 4);
	m->file = NULL;
	map_destroy(&m);
}
