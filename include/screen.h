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

#ifndef SCREEN_H
# define SCREEN_H

# include <stdlib.h>

# include "libft.h"
# include "point.h"
# include "mlx.h"
# include "error_code.h"
# include "pixel.h"

typedef struct s_screen
{
	void		*mlx;
	void		*win;
	void		*ref;
	t_point		size;
	char		*pixel;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_screen;

t_error_code	screen_create(t_screen **ret, void *mlx);
void			screen_destroy(t_screen **obj);
void			screen_color_pixel(t_screen *s, t_point pos, int color);
void			screen_draw_background(t_screen *screen, int celling, \
	int floor);
void			screen_put_screen_to_window(t_screen *s);


#endif
