/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 09:50:39 by al7aro            #+#    #+#             */
/*   Updated: 2023/02/16 11:19:44 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "mlx.h"

void	img_pix_put(t_sprite *img, int x, int y, int color)
{
	char    *pixel;

    pixel = img->pixel + (y * img->line_size + x * (img->bits_per_pixel / 8));
	*(int *)pixel = color;
}

int get_img_color(t_sprite *img, int x, int y)
{
	return (*(int *)(img->pixel + (y * img->line_size + x * (img->bits_per_pixel / 8))));
}

void	clear_img(t_sprite *img)
{
	int i;
	int j;

	i = 0;
	while (i < img->size.y)
	{
		j = 0;
		while (j < img->size.x)
		{
			img_pix_put(img, j, i, 0);
			++j;
		}
		++i;
	}
}

static t_error_code	main2(void *mlx, void *win, char **argv)
{
	t_map			*m;
	t_error_code	err;
	t_sprite		*s;
	t_sprite		*s2;

	err = map_create(&m, mlx);
	if (SUCCESS == err)
	{
		err = map_read_raw(m, argv[1]);
		if (SUCCESS == err)
			err = map_validate(m->file);
		if (SUCCESS == err)
			err = map_load(m);
		if (SUCCESS == err)
			err = map_post_load_validation(m);
		s = m->sm->sprites[0];

		int y = 0;
		int i = 0;
		while (y < 200)
		{
			while (i < 400)
			{
				t_rgb tmp = m->pm->planes[0]->color;
				int rgb = tmp.red;
				rgb = (rgb << 8) + tmp.green;
				rgb = (rgb << 8) + tmp.blue;
				img_pix_put(s, i, y, rgb);
				++i;
			}
			++y;
		}
		mlx_put_image_to_window(mlx, win, s->ref, 0, 0);
		clear_img(s);
		mlx_put_image_to_window(mlx, win, s->ref, 100, 100);
		mlx_loop(mlx);
		map_destroy(&m);
	}
	return (err);
}

int	main(int argc, char **argv)
{
	void			*mlx;
	void			*win;
	t_error_code	err;

	err = parser_arg_check(argc, argv);
	if (SUCCESS == err)
	{
		mlx = mlx_init();
		win = mlx_new_window(mlx, 400, 400, "hey");
		err = main2(mlx, win, argv);
		mlx_destroy_window(mlx, win);
		mlx_destroy_display(mlx);
		free(mlx);
	}
	return (error_code_print_on_exit(err));
}

// TODO remove this test main
// int	main(int argc, char **argv)
// {
// 	t_error_code	err;
// 	void			*mlx;
// 	void			*win;
// 	t_sprite		*s;

// 	err = parser_arg_check(argc, argv);
// 	if (SUCCESS == err)
// 	{
// 		mlx = mlx_init();
// 		win = mlx_new_window(mlx, 400, 400, "hey");
// 		err = sprite_create(&s, mlx);
// 		if (SUCCESS == err)
// 		{
// 			err = sprite_load(s, "./resource/xpm/wall.xpm");
// 			if (SUCCESS == err)
// 			{
// 				mlx_put_image_to_window(mlx, win, s->ref, s->size.x, s->size.y);
// 				sprite_destroy(&s);
// 			}
// 		}
// 		mlx_destroy_window(mlx, win);
// 		mlx_destroy_display(mlx);
// 		free(mlx);
// 	}
// 	return (error_code_print_on_exit(err));
// }
