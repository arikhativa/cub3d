/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/02/13 12:13:04 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"

t_image	*image_create(void)
{
	t_image	*ret;

	ret = (t_image *)ft_calloc(1, sizeof(t_image));
	if (!ret)
		return (NULL);
	return (ret);
}

void	image_destroy(t_image *obj)
{
	ft_bzero(obj, sizeof(t_image));
	free(obj);
}

static void	init_path(char path[MAX_PATH], char *file_name)
{
	char	*xpm_path;
	int		i;
	int		j;

	i = 0;
	j = 0;
	xpm_path = XPM_PATH;
	while (xpm_path[i])
	{
		path[i] = xpm_path[i];
		++i;
	}
	while (file_name[j])
	{
		path[j + i] = file_name[j];
		++j;
	}
	path[j + i] = '\0';
}

int	image_load(t_image *img, void *mlx, char *file_name)
{
	char	path[MAX_PATH];

	init_path(path, file_name);
	img->ref = mlx_xpm_file_to_image(mlx, path, &(img->size.x), \
		&(img->size.y));
	if (!img->ref)
		return (ERROR);
	img->pixel = mlx_get_data_addr(img->ref, &(img->bits_per_pixel), \
		&(img->line_size), &(img->endian));
	if (!img->pixel)
		return (ERROR);
	return (SUCCESS);
}

void	image_put(t_image *img, void* mlx, void *win, int x, int y)
{
	mlx_put_image_to_window(
		mlx, \
		win, \
		img->ref, \
		x, \
		y \
	);
}
