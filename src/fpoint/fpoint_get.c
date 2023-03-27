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

double	fpoint_get_distance(t_fpoint p1, t_fpoint p2)
{
	double	x;
	double	y;

	x = p2.x - p1.x;
	y = p2.y - p1.y;
	return (sqrt(x * x + y * y));
}
