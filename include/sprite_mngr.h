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

#ifndef SPRITE_MNGR_H
# define SPRITE_MNGR_H

# include <stdlib.h>

# include "libft.h"
# include "error_code.h"
# include "sprite.h"
# include "direction.h"

# define SPRITES_IN_MAP 4

typedef struct s_sprite_mngr
{
	t_sprite	*sprites[SPRITES_IN_MAP];
}				t_sprite_mngr;

t_error_code	sprite_mngr_create(t_sprite_mngr **ret, void *mlx);
void			sprite_mngr_destroy(t_sprite_mngr **obj);

#endif
