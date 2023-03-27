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

#include "fpoint.h"
#include "unit_test.h"

void	test_fpoint(void)
{
	t_fpoint	p1;
	t_fpoint	p2;

	p1 = fpoint_init(1.1, 2.2);
	p2 = fpoint_copy(p1);
	CU_ASSERT_EQUAL(p1.x, 1.1);
	CU_ASSERT_EQUAL(p1.y, 2.2);
	CU_ASSERT_EQUAL(p1.x, p2.x);
	CU_ASSERT_EQUAL(p1.y, p2.y);
}

void	test_fpoint_init(void)
{
	t_fpoint		p;

	p = fpoint_init(5.5, 6.5);
	CU_ASSERT_EQUAL(5.5, p.x);
	CU_ASSERT_EQUAL(6.5, p.y);
}

void	test_fpoint_to_point(void)
{
	t_fpoint		fp;
	t_point			p;

	fp = fpoint_init(5.8, 6.99);
	p = fpoint_to_point(fp);
	CU_ASSERT_EQUAL(5, p.x);
	CU_ASSERT_EQUAL(6, p.y);	
}

void	test_point_to_fpoint(void)
{
	t_fpoint		p;
	t_point			p2;

	p2 = point_init(5, 6);
	p = point_to_fpoint(p2);
	CU_ASSERT_EQUAL(5.0, p.x);
	CU_ASSERT_EQUAL(6.0, p.y);	
}

void	test_small_round_up(void)
{
	t_fpoint	fp;
	t_point		p;
	fp = fpoint_init(0, 2.999);
	p = fpoint_to_point(fp);
	CU_ASSERT_EQUAL(p.x, 0);
	CU_ASSERT_EQUAL(p.y, 3);
}
