/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/02/13 12:09:42 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"

t_point	*point_create(void)
{
	t_point	*ret;

	ret = (t_point *)ft_calloc(1, sizeof(t_point));
	if (!ret)
		return (NULL);
	return (ret);
}

void	point_destroy(t_point *obj)
{
	ft_bzero(obj, sizeof(t_point));
	free(obj);
}
