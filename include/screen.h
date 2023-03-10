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
	void		*ref;
	t_point		size;
	char		*pixel;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_screen;

t_error_code	screen_create(t_screen **ret, void *mlx);
void			screen_destroy(t_screen **obj);

#endif
