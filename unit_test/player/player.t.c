/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.t.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:47:50 by yrabby            #+#    #+#             */
/*   Updated: 2023/02/15 13:48:02 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "unit_test.h"

void	test_player_create_destroy(void)
{
	t_error_code	err;
	t_player		*obj;

	obj = NULL;
	err = player_create(&obj);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	player_destroy(&obj);
	CU_ASSERT_PTR_NULL(obj);
}

void	test_player_init(void)
{
	t_error_code	err;
	t_player		*obj;

	obj = NULL;
	err = player_create(&obj);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	player_init(obj, (t_fpoint){1.0, 2.0}, NORTH);
	CU_ASSERT_DOUBLE_EQUAL(obj->pos.x, 1.5, 0.00001);
	CU_ASSERT_DOUBLE_EQUAL(obj->pos.y, 2.5, 0.00001);
	CU_ASSERT_EQUAL(obj->dir, NORTH);
	player_destroy(&obj);
	CU_ASSERT_PTR_NULL(obj);
}
