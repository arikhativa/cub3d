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

#include "screen.h"

t_error_code	screen_create(t_screen **ret)
{
	t_screen		*tmp;

	if (!ret)
		return (ERROR);
	tmp = (t_screen *)ft_calloc(1, sizeof(t_screen));
	if (!tmp)
		return (ALLOCATION_ERROR);
	*ret = tmp;
	return (SUCCESS);
}

t_error_code	screen_init(t_screen *s, void *mlx)
{
	s->mlx = mlx;
	s->size = point_init(SCREEN_SIZE_X, SCREEN_SIZE_Y);
	s->ref = mlx_new_image(s->mlx, s->size.x, s->size.y);
	if (!s->ref)
		return (MLX_NEW_ING);
	s->pixel = mlx_get_data_addr(s->ref, &(s->bits_per_pixel), \
		&(s->line_size), &(s->endian));
	if (!s->pixel)
		return (SPRITE_LOAD_GET_DATA_ADDR);
	s->win = mlx_new_window(s->mlx, s->size.x, s->size.y, CUB3D_STR);
	if (!s->win)
		return (MLX_NEW_WIN);
	return (SUCCESS);
}

void	screen_destroy(t_screen **obj)
{
	t_screen	*tmp;

	if (!obj || !*obj)
		return ;
	tmp = *obj;
	if (tmp->ref)
		mlx_destroy_image(tmp->mlx, tmp->ref);
	if (tmp->win)
		mlx_destroy_window(tmp->mlx, tmp->win);
	ft_bzero(tmp, sizeof(t_screen));
	free(tmp);
	*obj = NULL;
}

