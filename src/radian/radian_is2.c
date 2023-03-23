/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radian_is2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/03/23 12:05:01 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "radian.h"

t_bool	radian_is_east(double radian)
{
	radian = radian_set_boundaries(radian);
	return (radian == 0);
}

t_bool	radian_is_north(double radian)
{
	radian = radian_set_boundaries(radian);
	return (radian == M_PI / 2);
}

t_bool	radian_is_west(double radian)
{
	radian = radian_set_boundaries(radian);
	return (radian == M_PI);
}

t_bool	radian_is_south(double radian)
{
	radian = radian_set_boundaries(radian);
	return (radian == (3 * M_PI) / 2);
}
