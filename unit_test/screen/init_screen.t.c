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

CU_TestInfo	g_screen_tests[] = {
{
	"test_screen_create_destroy",
	test_screen_create_destroy,
},
	CU_TEST_INFO_NULL,
};
