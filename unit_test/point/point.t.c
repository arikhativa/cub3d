/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.t.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:21:17 by yoav              #+#    #+#             */
/*   Updated: 2023/02/14 12:32:10 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"
#include "unit_test.h"

void	test_point(void)
{
	t_point	p1;
	t_point	p2;

	p1 = point_init(1, 2);
	p2 = point_copy(p1);
	CU_ASSERT_EQUAL(p1.x, 1);
	CU_ASSERT_EQUAL(p1.y, 2);
	CU_ASSERT_EQUAL(p1.x, p2.x);
	CU_ASSERT_EQUAL(p1.y, p2.y);
}
