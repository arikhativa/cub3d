/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utest.t.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:05:13 by yrabby            #+#    #+#             */
/*   Updated: 2023/02/14 10:09:20 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

CU_TestInfo	g_map_tests[] = {
{
	"test_map_is_closed_large",
	test_map_is_closed_large,
},
{
	"test_map_is_closed_err1",
	test_map_is_closed_err1,
},
{
	"test_map_is_closed_err2",
	test_map_is_closed_err2,
},
{
	"test_map_is_closed",
	test_map_is_closed,
},
{
	"test_map_load_player_err_dup_player",
	test_map_load_player_err_dup_player,
},
{
	"test_map_load_player_err_no_player",
	test_map_load_player_err_no_player,
},
{
	"test_map_load_player",
	test_map_load_player,
},
{
	"test_map_get_size",
	test_map_get_size,
},
{
	"test_map_get_map_index",
	test_map_get_map_index,
},
{
	"test_map_create_destroy",
	test_map_create_destroy,
},
{
	"test_map_validate",
	test_map_validate,
},
{
	"test_map_validate_ext_bad_prefix",
	test_map_validate_ext_bad_prefix,
},
{
	"test_map_validate_ext_bad_sprite_file",
	test_map_validate_ext_bad_sprite_file,
},
{
	"test_map_validate_ext_bad_char_in_plane",
	test_map_validate_ext_bad_char_in_plane,
},
{
	"test_map_validate_ext_missing_plane_color",
	test_map_validate_ext_missing_plane_color,
},
{
	"test_map_validate_map_not_bottom",
	test_map_validate_map_not_bottom,
},
{
	"test_map_validate_ext_invalid_line",
	test_map_validate_ext_invalid_line,
},
{
	"test_map_validate_ext_bad_color",
	test_map_validate_ext_bad_color,
},
	CU_TEST_INFO_NULL,
};
