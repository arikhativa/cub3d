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

#include "pixel.h"

char	*pixel_increment_y(char *pixel, int y, int line_size)
{
	return (pixel + y * line_size);
}

char	*pixel_increment_x(char *pixel, int x, int bits_per_pixel)
{
	return (pixel + x * (bits_per_pixel / BITS_IN_CHAR));
}
