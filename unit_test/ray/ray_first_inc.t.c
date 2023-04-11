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

#include "ray.h"
#include "unit_test.h"

void	test_1(void)
{
	double	pos = 0.4;
	double	inc = 1;
	double	ret;

	ret = get_first_inc(pos, inc);
	CU_ASSERT_DOUBLE_EQUAL(ret, 0.6, 0.0001);
}

void	test_2(void)
{
	double	pos = 11.4;
	double	inc = -1;
	double	ret;

	ret = get_first_inc(pos, inc);
	CU_ASSERT_DOUBLE_EQUAL(ret, -0.4, 0.0001);
}

void	test_3(void)
{
	double	pos = -11.4;
	double	inc = 1;
	double	ret;

	ret = get_first_inc(pos, inc);
	CU_ASSERT_DOUBLE_EQUAL(ret, 0.4, 0.0001);
}

void	test_4(void)
{
	double	pos = -11.4;
	double	inc = -1;
	double	ret;

	ret = get_first_inc(pos, inc);
	CU_ASSERT_DOUBLE_EQUAL(ret, -0.6, 0.0001);
}

void	test_ray_first_inc(void)
{
	test_1();
	test_2();
	test_3();
	test_4();
}
