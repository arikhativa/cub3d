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

CU_TestInfo	g_game_tests[] = {
{
	"test_game_create_destroy",
	test_game_create_destroy,
},
	CU_TEST_INFO_NULL,
};
