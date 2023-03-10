/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/02/16 10:48:47 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# include <stdlib.h>

# include "mlx.h"
# include "libft.h"
# include "error_code.h"
# include "macro.h"
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
}				t_sprite;

t_error_code	sprite_create(t_sprite **ret, void *mlx);
t_error_code	sprite_load(t_sprite *s, char *path);
t_bool			sprite_is_loaded(t_sprite *s);
void			sprite_unload(t_sprite *s);
void			sprite_destroy(t_sprite **obj);
int				sprite_get_pixel_color(t_sprite *s, t_point pos);

#endif
