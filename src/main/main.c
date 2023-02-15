/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 09:50:39 by al7aro            #+#    #+#             */
/*   Updated: 2023/02/15 10:36:19 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "mlx.h"

// TODO should be removed - here only for testing libx
int	main(int argc, char **argv, char **envp)
{
	t_error_code	err;
	void			*mlx;
	void			*mlx_win;

	(void)argc;
	(void)argv;
	(void)envp;
	err = SUCCESS;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	(void)mlx_win;
	mlx_loop(mlx);
	return (error_code_print_internal_err(err));
}
