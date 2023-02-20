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

#include "plane_mngr.h"
#include "unit_test.h"

void	test_plane_mngr_create_destroy(void)
{
	t_error_code	err;
	t_plane_mngr	*pm;
	t_rgb		color = {1, 2, 3};

	pm = NULL;
	err = plane_mngr_create(&pm);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	plane_mngr_init(pm, PLANE_TYPE_CEILING, color);
	t_plane *p = plane_mngr_get_plane(pm, PLANE_TYPE_CEILING);
	CU_ASSERT_EQUAL(p->color.red, color.red);
	CU_ASSERT_EQUAL(p->color.blue, color.blue);
	CU_ASSERT_EQUAL(p->color.green, color.green);
	plane_mngr_destroy(&pm);
	CU_ASSERT_PTR_NULL(pm);
}
