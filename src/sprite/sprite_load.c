/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_load.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:36:01 by yrabby            #+#    #+#             */
/*   Updated: 2023/02/16 10:59:46 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite.h"

t_error_code	sprite_load(t_sprite *s, char *path)
{
	s->ref = mlx_xpm_file_to_image(s->mlx, path, &(s->size.x), \
		&(s->size.y));
	if (!s->ref)
		return (SPRITE_LOAD_FILE_TO_IMG);
	s->pixel = mlx_get_data_addr(s->ref, &(s->bits_per_pixel), \
		&(s->line_size), &(s->endian));
	if (!s->pixel)
		return (SPRITE_LOAD_GET_DATA_ADDR);
	return (SUCCESS);
}

void	sprite_unload(t_sprite *s)
{
	mlx_destroy_image(s->mlx, s->ref);
}

t_bool	sprite_is_loaded(t_sprite *s)
{
	if (!s)
		return (FALSE);
	return (!!s->ref);
}
