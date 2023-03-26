/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radian.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/03/23 11:46:39 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADIAN_H
# define RADIAN_H

# include "math.h"
# include "macro.h"
# include "direction.h"

double		radian(double degree);
t_direction	radian_get_perfect_direction(double radian);
t_direction	radian_get_direction(double radian);
double		radian_set_boundaries(double radian);
t_direction	radian_get_dir(double radian);
t_bool		radian_is_north(double radian);
t_bool		radian_is_south(double radian);
t_bool		radian_is_east(double radian);
t_bool		radian_is_west(double radian);
t_bool		radian_is_north_east(double radian);
t_bool		radian_is_north_west(double radian);
t_bool		radian_is_south_east(double radian);
t_bool		radian_is_south_west(double radian);
t_bool		radian_is_perfect_north_east(double radian);
t_bool		radian_is_perfect_north_west(double radian);
t_bool		radian_is_perfect_south_west(double radian);
t_bool		radian_is_perfect_south_east(double radian);

#endif
