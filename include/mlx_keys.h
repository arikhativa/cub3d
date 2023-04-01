/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_keys.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:57:17 by ycarro            #+#    #+#             */
/*   Updated: 2023/03/29 15:38:48 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_KEYS_H
# define MLX_KEYS_H

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
#  define KEY_ESC	18
# endif
#endif
