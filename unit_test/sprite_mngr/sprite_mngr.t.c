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

#include "sprite_mngr.h"
#include "unit_test.h"

void	test_sprite_mngr_create_destroy(void)
{
	t_error_code	err;
	t_sprite_mngr		*obj;

	obj = NULL;
	err = sprite_mngr_create(&obj, g_mlx);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	sprite_mngr_destroy(&obj);
	CU_ASSERT_PTR_NULL(obj);
}
