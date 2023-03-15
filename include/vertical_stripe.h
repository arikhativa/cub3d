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

#ifndef VERTICAL_STRIPE_H
# define VERTICAL_STRIPE_H

# include <stdlib.h>

# include "screen.h"
# include "sprite.h"
# include "point.h"
# include "error_code.h"

typedef struct s_vertical_stripe
{
	t_screen	*screen;
	t_sprite	*sprite;
	t_point		screen_pos;
	double		sprite_x_pos;
	double		num_of_pixels;
}				t_vertical_stripe;

t_error_code	vertical_stripe_create(t_vertical_stripe **ret);
void			vertical_stripe_init(t_vertical_stripe *vs, t_screen *s);
void			vertical_stripe_draw(t_vertical_stripe *vs);
void			vertical_stripe_destroy(t_vertical_stripe **obj);
void			vertical_stripe_set_arg(t_vertical_stripe *vs, \
	t_point screen_pos,	double sprite_x, int num_of_pixels);

#endif
