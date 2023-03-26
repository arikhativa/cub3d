/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpoint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/03/24 17:20:29 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fpoint.h"

t_fpoint	fpoint_init(double x, double y)
{
	return ((t_fpoint){x, y});
}

t_fpoint	fpoint_copy(t_fpoint src)
{
	return ((t_fpoint){src.x, src.y});
}

// TODO create a little round func to make sure values like 2.999999 will be 3 and not 2
t_point	fpoint_to_point(t_fpoint p)
{
	t_point		result;
	double		remainder;
	int			aa;

	result.x = (int)p.x;
	result.y = (int)p.y;

	aa = round(p.y);
	remainder = aa - p.y;
	if (remainder < 0.01)
	{
		printf("aa: %d\n", aa);
		printf("px: %lf\n", p.y);
		printf("remainder: %lf\n", remainder);
		result.y = (int)round(p.y);
	}

	// remainder = p.y - (int)p.y;
	// if (remainder < 0.01)
	// 	result.y = (int)round(p.y);
	return (result);
}

t_fpoint	point_to_fpoint(t_point p)
{
	return ((t_fpoint){(double)p.x, (double)p.y});
}

void	fpoint_print(t_fpoint p)
{
	printf("{x: %lf, y: %lf}", p.x, p.y);
}
