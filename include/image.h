/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/02/13 12:12:06 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include <stdlib.h>

# include "error_code.h"
# include "macro.h"
# include "point.h"
# include "mlx.h"
# include "libft.h"

typedef struct s_image
{
	void		*ref;
	t_point		size;
	char		*pixel;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

t_image		*image_create(void);
void		image_destroy(t_image *obj);
int			image_load(t_image *img, void *mlx, char *file_name);
void		image_put(t_image *img, void* mlx, void *win, int x, int y);

#endif
