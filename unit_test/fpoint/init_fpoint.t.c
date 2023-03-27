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

CU_TestInfo	g_fpoint_tests[] = {
{
	"test_fpoint_to_point",
	test_fpoint_to_point,
},
{
	"test_point_to_fpoint",
	test_point_to_fpoint,
},
{
	"test_fpoint_init",
	test_fpoint_init,
},
{
	"test_small_round_up",
	test_small_round_up,
},
{
	"test_fpoint",
	test_fpoint,
},
	CU_TEST_INFO_NULL,
};
