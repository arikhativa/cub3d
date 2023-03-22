/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpoint.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/03/22 09:29:54 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FPOINT_H
# define FPOINT_H

# include "point.h"

typedef struct s_fpoint
{
	double	x;
	double	y;
}				t_fpoint;

t_fpoint	fpoint_init(double x, double y);
t_fpoint	fpoint_copy(t_fpoint src);
t_point		fpoint_to_point(t_fpoint p);
t_fpoint	point_to_fpoint(t_point p);
void		fpoint_print(t_fpoint p);

#endif
