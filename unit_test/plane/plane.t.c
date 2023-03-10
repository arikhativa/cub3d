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

#include "plane.h"
#include "unit_test.h"

void	test_plane_create_destroy(void)
{
	t_error_code	err;
	t_plane		*obj;
	t_rgb		color = {1, 2, 3};

	obj = NULL;
	err = plane_create(&obj);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	plane_init(obj, color);
	CU_ASSERT_EQUAL(obj->color.red, color.red);
	CU_ASSERT_EQUAL(obj->color.blue, color.blue);
	CU_ASSERT_EQUAL(obj->color.green, color.green);
	plane_destroy(&obj);
	CU_ASSERT_PTR_NULL(obj);
}
