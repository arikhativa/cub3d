/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/02/14 12:29:20 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"

t_point	point_init(int x, int y)
{
	t_point	ret;

	ret = (t_point){x, y};
	return (ret);
	return (ret);
}

t_point	point_copy(t_point src)
{
	t_point	ret;

	ret = (t_point){src.x, src.y};
	return (ret);
}
