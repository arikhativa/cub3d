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

#ifndef PLANE_H
# define PLANE_H

# include <stdlib.h>

# include "libft.h"
# include "error_code.h"
# include "rgb.h"

typedef struct s_plane
{
	t_rgb	color;
}				t_plane;

t_error_code	plane_create(t_plane **ret);
void			plane_init(t_plane *p, t_rgb color);
void			plane_destroy(t_plane **obj);
void			plane_print(t_plane *p);

#endif
