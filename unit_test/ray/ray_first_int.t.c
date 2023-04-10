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

double		get_first_inc(double pos, double inc);

// start   {x: 6.326352, y: 4.484808}
// coll    {x: 3.721123, y: 2.055392}
void	test_0_33(void)
{
	double	pos = -6234.326352;
	double	inc = -1;
	double	res;

	res = get_first_inc(pos, inc);
	printf("res = %lf\n", res);
	CU_ASSERT_DOUBLE_EQUAL(res, 0.33, 0.01);

}

void	test_ray_first_inc(void)
{
	test_0_33();
}