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

t_error_code	screen_create(t_screen **ret, void *mlx)
{
	t_screen		*tmp;

	if (!ret)
		return (ERROR);
	tmp = (t_screen *)ft_calloc(1, sizeof(t_screen));
	if (!tmp)
		return (ALLOCATION_ERROR);
	tmp->mlx = mlx;
	tmp->size = point_init(SCREEN_SIZE_X, SCREEN_SIZE_Y);
	tmp->ref = mlx_new_image(tmp->mlx, tmp->size.x, tmp->size.y);
	if (!tmp->ref)
		return (MLX_NEW_ING);
	tmp->pixel = mlx_get_data_addr(tmp->ref, &(tmp->bits_per_pixel), \
		&(tmp->line_size), &(tmp->endian));
	if (!tmp->pixel)
		return (SPRITE_LOAD_GET_DATA_ADDR);
	tmp->win = mlx_new_window(tmp->mlx, tmp->size.x, tmp->size.y, CUB3D_STR);
	if (!tmp->win)
		return (MLX_NEW_WIN);
	*ret = tmp;
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

