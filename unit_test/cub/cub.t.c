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

#include "cub.h"
#include "unit_test.h"

void	test_cub_get_line_type(void)
{
	t_line_type	type = cub_get_line_type("SO /path");
	CU_ASSERT_EQUAL(type, LINE_TYPE_SOUTH);
	type = cub_get_line_type("bad line");
	CU_ASSERT_EQUAL(type, LINE_TYPE_INVALID);
	type = cub_get_line_type("   0  0 1 1 N");
	CU_ASSERT_EQUAL(type, LINE_TYPE_MAP);
	type = cub_get_line_type("C 100,23,0");
	CU_ASSERT_EQUAL(type, LINE_TYPE_CEILING);
}
