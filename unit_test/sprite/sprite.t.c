/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.t.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:21:17 by yoav              #+#    #+#             */
/*   Updated: 2023/02/16 10:49:07 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite.h"
#include "unit_test.h"

void	test_sprite_create_destroy(void)
{
	t_error_code	err;
	t_sprite		*obj;

	obj = NULL;
	err = sprite_create(&obj);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	sprite_destroy(&obj);
	CU_ASSERT_PTR_NULL(obj);
}

void	test_sprite_is_loaded(void)
{
	t_sprite	*obj;
	t_error_code	err;
	t_bool	ret;

	ret = sprite_is_loaded(NULL);
	CU_ASSERT_EQUAL(ret, FALSE);

	err = sprite_create(&obj);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	ret = sprite_is_loaded(obj);
	CU_ASSERT_EQUAL(ret, FALSE);
	sprite_destroy(&obj);
}
