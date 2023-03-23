/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/02/15 13:55:57 by yrabby           ###   ########.fr       */
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

t_point	fpoint_to_point(t_fpoint p)
{
	return ((t_point){(int)p.x, (int)p.y});
}

t_fpoint	point_to_fpoint(t_point p)
{
	return ((t_fpoint){(double)p.x, (double)p.y});
}

void	fpoint_print(t_fpoint p)
{
	printf("{x: %f, y: %f}", p.x, p.y);
}
