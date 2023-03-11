/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/02/14 10:47:54 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RGB_H
# define RGB_H

typedef struct s_rgb
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}	t_rgb;

void	rgb_init(t_rgb *rgb, unsigned char red, unsigned char green, \
	unsigned char blue);
int		rgb_to_int(t_rgb *rgb);

#endif
