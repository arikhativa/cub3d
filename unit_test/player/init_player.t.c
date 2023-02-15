/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.t.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:05:13 by yrabby            #+#    #+#             */
/*   Updated: 2023/02/15 13:35:06 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

CU_TestInfo	g_player_tests[] = {
{
	"test_player_create_destroy",
	test_player_create_destroy,
},
{
	"test_player_init",
	test_player_init,
},
	CU_TEST_INFO_NULL,
};
