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

void	test_map_validate(void)
{
	t_error_code	err;
	char *file[] = {
		"NO ./resource/xpm/wall.xpm",
		"SO ./resource/xpm/wall.xpm",
		"WE ./resource/xpm/wall.xpm",
		"EA ./resource/xpm/wall.xpm",
		"F 100,23,0",
		"C 100,23,0",
		" 1111",
		"10N1",
		"1  1",
		"1111",
		NULL,
	};

	err = map_validate(file);
	CU_ASSERT_EQUAL(SUCCESS, err);
}

void	test_map_validate_ext_bad_prefix(void)
{
	t_error_code	err;
	char *file[] = {
		"BadPrefix ./resource/xpm/wall.xpm",
		"SO ./resource/xpm/wall.xpm",
		"WE ./resource/xpm/wall.xpm",
		"EA ./resource/xpm/wall.xpm",
		"F 100,23,0",
		"C 100,23,0",
		" 1111",
		"10N1",
		"1  1",
		"1111",
		NULL,
	};

	err = map_validate(file);
	CU_ASSERT_EQUAL(EXT_INVALID_LINE, err);
}

void	test_map_validate_ext_bad_sprite_file(void)
{
	t_error_code	err;
	char *file[] = {
		"NO /no/path",
		"SO ./resource/xpm/wall.xpm",
		"WE ./resource/xpm/wall.xpm",
		"EA ./resource/xpm/wall.xpm",
		"F 100,23,0",
		"C 100,23,0",
		" 1111",
		"10N1",
		"1  1",
		"1111",
		NULL,
	};

	err = map_validate(file);
	CU_ASSERT_EQUAL(EXT_BAD_SPRITE_FILE, err);
}

void	test_map_validate_ext_bad_char_in_plane(void)
{
	t_error_code	err;
	char *file[] = {
		"NO ./resource/xpm/wall.xpm",
		"SO ./resource/xpm/wall.xpm",
		"WE ./resource/xpm/wall.xpm",
		"EA ./resource/xpm/wall.xpm",
		"F aaaaa,23,0",
		"C 100,23,0",
		" 1111",
		"10N1",
		"1  1",
		"1111",
		NULL,
	};

	err = map_validate(file);
	CU_ASSERT_EQUAL(EXT_BAD_CHAR_IN_PLANE, err);
}

void	test_map_validate_ext_missing_plane_color(void)
{
	t_error_code	err;
	char *file[] = {
		"NO ./resource/xpm/wall.xpm",
		"SO ./resource/xpm/wall.xpm",
		"WE ./resource/xpm/wall.xpm",
		"EA ./resource/xpm/wall.xpm",
		"F 100,",
		"C 100,23,0",
		" 1111",
		"10N1",
		"1  1",
		"1111",
		NULL,
	};

	err = map_validate(file);
	CU_ASSERT_EQUAL(EXT_MISSING_PLANE_COLOR, err);
}

void	test_map_validate_map_not_bottom(void)
{
	t_error_code	err;
	char *file[] = {
		"NO ./resource/xpm/wall.xpm",
		"SO ./resource/xpm/wall.xpm",
		"WE ./resource/xpm/wall.xpm",
		"EA ./resource/xpm/wall.xpm",
		"F 100,23,0",
		" 1111",
		"10N1",
		"1  1",
		"1111",
		"C 100,23,0",
		NULL,
	};

	err = map_validate(file);
	CU_ASSERT_EQUAL(EXT_MAP_NOT_AT_BOTTOM, err);
}

void	test_map_validate_ext_invalid_line(void)
{
	t_error_code	err;
	char *file[] = {
		"heyyyy",
		"SO ./resource/xpm/wall.xpm",
		"WE ./resource/xpm/wall.xpm",
		"EA ./resource/xpm/wall.xpm",
		"F 100,23,0",
		"C 100,23,0",
		" 1111",
		"10N1",
		"1  1",
		"1111",
		NULL,
	};

	err = map_validate(file);
	CU_ASSERT_EQUAL(EXT_INVALID_LINE, err);
}

void	test_map_validate_ext_bad_color(void)
{
	t_error_code	err;
	char *file[] = {
		"NO ./resource/xpm/wall.xpm",
		"SO ./resource/xpm/wall.xpm",
		"WE ./resource/xpm/wall.xpm",
		"EA ./resource/xpm/wall.xpm",
		"F -100,23,0",
		"C 100,23,0",
		" 1111",
		"10N1",
		"1  1",
		"1111",
		NULL,
	};

	err = map_validate(file);
	CU_ASSERT_EQUAL(EXT_BAD_COLOR, err);
}
