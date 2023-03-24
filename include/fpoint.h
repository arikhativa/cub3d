/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpoint.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/03/24 17:03:28 by ycarro           ###   ########.fr       */
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
