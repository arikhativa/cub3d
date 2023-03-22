/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/02/15 13:55:57 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rgb.h"

void	rgb_init(t_rgb *rgb, unsigned char red, unsigned char green, \
	unsigned char blue)
{
	rgb->red = red;
	rgb->green = green;
	rgb->blue = blue;
}

int	rgb_to_int(t_rgb *rgb)
{
	return (rgb->red << 16 | rgb->green << 8 | rgb->blue);
}
