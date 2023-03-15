/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utest.t.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:21:17 by yoav              #+#    #+#             */
/*   Updated: 2023/02/14 12:27:39 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "unit_test.h"

void	test_game_create_destroy(void)
{
	t_error_code	err;
	t_game		*obj;

	obj = NULL;
	err = game_create(&obj);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	game_destroy(&obj);
	CU_ASSERT_PTR_NULL(obj);
}
