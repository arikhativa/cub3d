/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/04/18 14:30:12 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# include <math.h>
# include <stdlib.h>

# include "mlx.h"
# include "libft.h"
# include "radian.h"
# include "error_code.h"
# include "macro.h"
# include "fpoint.h"
# include "point.h"
# include "pixel.h"

typedef struct s_sprite
{
	void		*mlx;
	void		*ref;
	t_point		size;
	char		*pixel;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
	t_direction	index;
}				t_sprite;

t_error_code	sprite_create(t_sprite **ret);
void			sprite_init(t_sprite *s, char *mlx);
t_error_code	sprite_load(t_sprite *s, char *path);
t_bool			sprite_is_loaded(t_sprite *s);
void			sprite_unload(t_sprite *s);
void			sprite_destroy(t_sprite **obj);
int				sprite_get_pixel_color(t_sprite *s, t_point pos);
int				sprite_get_stripe(t_sprite *s, t_fpoint collision_point);

#endif
