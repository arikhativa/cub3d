/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_keys                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/02/15 13:58:46 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_keys.h"

t_bool	mlx_keys_is_vision(int keycode)
{
	return (keycode == KEY_LEFT || keycode == KEY_RIGHT);
}

t_bool	mlx_keys_is_movement(int keycode)
{
	return (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S \
		|| keycode == KEY_D);
}

t_bool	mlx_keys_is_exit(int keycode)
{
	return (keycode == KEY_ESC);
}
