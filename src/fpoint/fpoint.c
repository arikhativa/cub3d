/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpoint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/04/18 16:54:10 by yrabby           ###   ########.fr       */
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
	printf("{x: %.20lf, y: %.20lf}", p.x, p.y);
}

double	fpoint_get_distance(t_fpoint p1, t_fpoint p2)
{
	return (sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)));
}

t_bool	fpoint_equal(t_fpoint a, t_fpoint b)
{
	return (a.x == b.x && a.y == b.y);
}
