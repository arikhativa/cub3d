/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 09:50:39 by al7aro            #+#    #+#             */
/*   Updated: 2023/02/13 12:15:49 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "mlx.h"

// TODO should be removed - here only for testing libx
int	main(int argc, char **argv, char **envp)
{
	t_image	*img;
	void	*mlx;
	void	*mlx_win;

	(void)argc;
	(void)argv;
	(void)envp;
	mlx = mlx_init();
	img = image_create();
	image_load(img, mlx, "wall.xpm");
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	(void)mlx_win;
	image_put(img, mlx, mlx_win, 50, 50);
	mlx_loop(mlx);
}
