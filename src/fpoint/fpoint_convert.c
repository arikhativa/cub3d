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

// TODO in a case of a very small reminder we should round to the nearest int
// e.g.
// 0.999
// should be rounded to 1
static int	round_if_needed(double d)
{
	double	remainder;
	int		i;

	i = (int)d;
	remainder = fmod(d, 1);
	if ((1 - remainder) < 0.001)
		return (i + 1);
	return (i);
}

t_point	fpoint_to_point(t_fpoint p)
{
	t_point		result;

	result.x = round_if_needed(p.x);
	result.y = round_if_needed(p.y);
	return (result);
}

t_fpoint	point_to_fpoint(t_point p)
{
	return ((t_fpoint){(double)p.x, (double)p.y});
}
