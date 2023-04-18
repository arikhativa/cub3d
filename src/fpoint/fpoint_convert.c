/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpoint_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/04/18 15:55:34 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fpoint.h"

static int	round_if_needed(double d)
{
	double	rem;
	int		i;

	i = (int)d;
	rem = fmod(d, 1.0);
	if ((1 - rem) < EPSILON)
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

t_bool	fpoint_is_corner(t_fpoint p)
{
	double	rem_x;
	double	rem_y;

	rem_x = fmod(p.x, 1.0);
	rem_y = fmod(p.y, 1.0);
	return ((rem_x < EPSILON || rem_x > (1 - EPSILON)) && \
		(rem_y < EPSILON || rem_y > (1 - EPSILON)));
}
