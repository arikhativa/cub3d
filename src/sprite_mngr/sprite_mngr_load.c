/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/02/15 13:55:57 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite_mngr.h"

t_error_code	sprite_mngr_load_sprite(t_sprite_mngr *sm, t_direction d, \
	char *path)
{
	if (sprite_is_loaded(sm->sprites[d]))
		return (EXT_DUPLICATE_SETTING);
	return (sprite_load(sm->sprites[d], path));
}
