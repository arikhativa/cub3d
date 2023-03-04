/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/02/15 13:47:28 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"

t_point	point_up(t_point p)
{
	return ((t_point){p.x, p.y - 1});
}

t_point	point_down(t_point p)
{
	return ((t_point){p.x, p.y + 1});
}

t_point	point_left(t_point p)
{
	return ((t_point){p.x - 1, p.y});
}

t_point	point_right(t_point p)
{
	return ((t_point){p.x + 1, p.y});
}
