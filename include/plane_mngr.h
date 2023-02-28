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

#ifndef PLANE_MNGR_H
# define PLANE_MNGR_H

# include <stdlib.h>

# include "libft.h"
# include "error_code.h"
# include "plane.h"

# define PLANES_IN_MAP 2

typedef enum e_plane_type
{
	PLANE_TYPE_FLOOR = 0,
	PLANE_TYPE_CEILING = 1,
	PLANE_TYPE_ERROR,
}	t_plane_type;

typedef struct s_plane_mngr
{
	t_plane	*planes[PLANES_IN_MAP];
}				t_plane_mngr;

t_error_code	plane_mngr_create(t_plane_mngr **ret);
void			plane_mngr_init(t_plane_mngr *pm, t_plane_type type, \
	t_rgb color);
void			plane_mngr_destroy(t_plane_mngr **obj);
t_plane			*plane_mngr_get_plane(t_plane_mngr *pm, t_plane_type type);
void			plane_mngr_print(t_plane_mngr *pm);

#endif
