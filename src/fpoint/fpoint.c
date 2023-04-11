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

void	fpoint_print(t_fpoint p)
{
	printf("{x: %lf, y: %lf}", p.x, p.y);
}

double	fpoint_get_distance(t_fpoint p1, t_fpoint p2)
{
	return (sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)));
}

t_bool		fpoint_equal(t_fpoint a, t_fpoint b)
{
	return (a.x == b.x && a.y == b.y);
}
