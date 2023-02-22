/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:48:17 by ycarro            #+#    #+#             */
/*   Updated: 2023/02/22 16:43:12 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_point	dda(char **map, t_player *p, t_ray	*ray_data, t_angle *ray_to_cast)
{
	set_incrementor(ray_data, ray_to_cast->radians);
	get_ray_data(ray_data, ray_to_cast->radians);
}

void	set_incrementor(t_ray *ray_data, double alpha)
{
	incrementor = ft_calloc(2, sizeof(double));
	while (alpha > (2 * M_PI))
		alpha -= (2 * M_PI);
	if (alpha >= (3.0 / 2.0) * M_PI)
	{
		incrementor[0] = 1;
		incrementor[1] = -1;
	}
	else if (alpha >= M_PI)
	{
		incrementor[0] = -1;
		incrementor[1] = -1;
	}
	else if (alpha >= (1.0 / 2.0) * M_PI)
	{
		incrementor[0] = -1;
		incrementor[1] = 1;
	}
	else
	{
		incrementor[0] = 1;
		incrementor[1] = 1;
	}
}

void	get_ray_data(t_ray *ray_data, double alpha, t_player *player)
{
	ray_data->slope = tan(alpha);
	ray_data->intercept = player->pos->y - (player->pos->x * ray_data->slope);
	ray_data->x_pos->x = player->pos->x;
	ray_data->x_pos->y = player->pos->y;
	ray_data->y_pos->x = player->pos->x;
	ray_data->y_pos->x = player->pos->y;
}
