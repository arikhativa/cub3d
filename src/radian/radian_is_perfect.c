/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radian_is.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/03/23 12:12:44 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "radian.h"

t_bool	radian_is_perfect_north_east(double radian)
{
	radian = radian_set_boundaries(radian);
	return (radian == M_PI / 4);
}

t_bool	radian_is_perfect_north_west(double radian)
{
	radian = radian_set_boundaries(radian);
	return (radian == 3 * M_PI / 2);
}

t_bool	radian_is_perfect_south_west(double radian)
{
	radian = radian_set_boundaries(radian);
	return (radian == 5 * M_PI / 4);
}

t_bool	radian_is_perfect_south_east(double radian)
{
	radian = radian_set_boundaries(radian);
	return (radian == 7 * M_PI / 4);
}
