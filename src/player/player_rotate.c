/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:46:30 by yrabby            #+#    #+#             */
/*   Updated: 2023/03/29 15:43:33 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	player_rotate_right(t_player *p)
{
	p->dir -= radian(ROTATION_SPEED);
}

void	player_rotate_left(t_player *p)
{
	p->dir += radian(ROTATION_SPEED);
}
