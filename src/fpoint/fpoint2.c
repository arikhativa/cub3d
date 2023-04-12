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

t_bool	fpoint_is_corner(t_fpoint p)
{
	double	rem_x;
	double	rem_y;
	double	epsilon;

	epsilon = 0.001;
	rem_x = fmod(p.x, 1.0);
	rem_y = fmod(p.y, 1.0);
	return ((rem_x < epsilon || rem_x > (1 - epsilon)) && \
		(rem_y < epsilon || rem_y > (1 - epsilon)));
}
