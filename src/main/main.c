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

static void	ignore(void *mlx, char **argv)
{
	t_map			*m;
	t_error_code	err;

	err = map_create(&m, mlx);
	if (SUCCESS == err)
	{
		err = map_read_raw(m, argv[1]);
		if (SUCCESS == err)
			err = map_validate(m->file);
		if (SUCCESS == err)
			err = map_load(m);
		if (SUCCESS == err)
			map_print(m);
		map_destroy(&m);
	}
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
		ignore(mlx, argv);
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
