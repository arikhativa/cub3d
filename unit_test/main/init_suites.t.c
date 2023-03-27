/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_suites.t.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:22:13 by yoav              #+#    #+#             */
/*   Updated: 2023/03/22 12:10:28 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

CU_SuiteInfo	g_suites[] = {
{
	"dll",
	init_suite,
	clean_suite,
	NULL,
	NULL,
	g_dll_tests,
},
{
	"parser",
	init_suite,
	clean_suite,
	NULL,
	NULL,
	g_parser_tests,
},
{
	"point",
	init_suite,
	clean_suite,
	NULL,
	NULL,
	g_point_tests,
},
{
	"player",
	init_suite,
	clean_suite,
	NULL,
	NULL,
	g_player_tests,
},
{
	"map",
	init_suite,
	clean_suite,
	NULL,
	NULL,
	g_map_tests,
},
{
	"sprite",
	init_suite,
	clean_suite,
	NULL,
	NULL,
	g_sprite_tests,
},
{
	"sprite_mngr",
	init_suite,
	clean_suite,
	NULL,
	NULL,
	g_sprite_mngr_tests,
},
{
	"plane",
	init_suite,
	clean_suite,
	NULL,
	NULL,
	g_plane_tests,
},
{
	"plane_mngr",
	init_suite,
	clean_suite,
	NULL,
	NULL,
	g_plane_mngr_tests,
},
{
	"cub",
	init_suite,
	clean_suite,
	NULL,
	NULL,
	g_cub_tests,
},
{
	"screen",
	init_suite,
	clean_suite,
	NULL,
	NULL,
	g_screen_tests,
},
{
	"dda",
	init_suite,
	clean_suite,
	NULL,
	NULL,
	g_dda_tests,
},
{
	"fpoint",
	init_suite,
	clean_suite,
	NULL,
	NULL,
	g_fpoint_tests,
},
{
	"ray",
	init_suite,
	clean_suite,
	NULL,
	NULL,
	g_ray_tests,
},
	CU_SUITE_INFO_NULL,
};
