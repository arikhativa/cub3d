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

#include "vertical_stripe.h"

t_error_code	vertical_stripe_create(t_vertical_stripe **ret)
{
	t_vertical_stripe		*tmp;

	if (!ret)
		return (ERROR);
	tmp = (t_vertical_stripe *)ft_calloc(1, sizeof(t_vertical_stripe));
	if (!tmp)
		return (ALLOCATION_ERROR);
	*ret = tmp;
	return (SUCCESS);
}

void	vertical_stripe_destroy(t_vertical_stripe **obj)
{
	t_vertical_stripe	*tmp;

	if (!obj || !*obj)
		return ;
	tmp = *obj;
	ft_bzero(tmp, sizeof(t_vertical_stripe));
	free(tmp);
	*obj = NULL;
}

void			vertical_stripe_init(t_vertical_stripe *vs, t_screen *s)
{
	vs->screen = s;
}

void	vertical_stripe_set_arg(t_vertical_stripe *vs, t_point screen_pos, \
	double sprite_x, int num_of_pixels)
{
	vs->screen_pos = screen_pos;
	vs->sprite_x_pos = sprite_x;
	vs->num_of_pixels = num_of_pixels;
}
