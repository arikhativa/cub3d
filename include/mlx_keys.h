/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_keys.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:57:17 by ycarro            #+#    #+#             */
/*   Updated: 2023/04/18 14:35:18 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_KEYS_H
# define MLX_KEYS_H

# include "macro.h"

# ifdef LINUX_ON
#  define KEY_W		119
#  define KEY_A		97
#  define KEY_D		100
#  define KEY_S		115
#  define KEY_LEFT	65361
#  define KEY_RIGHT	65363
#  define KEY_ESC	65307
# endif

# ifdef MAC_ON
#  define KEY_W		13	
#  define KEY_A		0
#  define KEY_D		2
#  define KEY_S		1
#  define KEY_LEFT	123
#  define KEY_RIGHT	124
#  define KEY_ESC	53
# endif

t_bool	mlx_keys_is_vision(int keycode);
t_bool	mlx_keys_is_movement(int keycode);
t_bool	mlx_keys_is_exit(int keycode);

#endif
