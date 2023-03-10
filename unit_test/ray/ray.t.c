/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.t.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:51:52 by ycarro            #+#    #+#             */
/*   Updated: 2023/03/10 20:01:53 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"
#include "math.h"
#include "ray.h"

void	test_check_steps(void)
{
	t_ray	ex_ray;

	ex_ray.x_pos.x = 0;
	ex_ray.x_pos.y = 0;
	ex_ray.y_pos.x = 100;
	ex_ray.y_pos.y = 100;
	ex_ray.incrementor.x = 1;
	ex_ray.incrementor.y = 1;
	ex_ray.slope = (1 / 4) * M_PI;
	ex_ray.intercept = 0;
	ray_increment(&ex_ray);
	ray_increment(&ex_ray);
	ray_increment(&ex_ray);
	ray_increment(&ex_ray);

	printf("\nXx_RAY: %d\n", ex_ray.x_pos.x);
	printf("\nXy_RAY: %d\n", ex_ray.x_pos.y);
	printf("\nYx_RAY: %d\n", ex_ray.y_pos.x);
	printf("\nYy_RAY: %d\n", ex_ray.y_pos.y);

}