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

typedef struct s_plane
{
	unsigned char	red;
	unsigned char	blue;
	unsigned char	green;
}				t_plane;

t_error_code	plane_create(t_plane **ret);
void			plane_init(t_plane *p, unsigned char red, unsigned char blue, \
	unsigned char green);
void			plane_destroy(t_plane **obj);

#endif
