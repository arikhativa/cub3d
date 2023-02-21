/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 09:50:39 by al7aro            #+#    #+#             */
/*   Updated: 2023/02/14 17:34:44 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "main.h"
#include "mlx.h"


typedef struct	s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		block[2];
}				t_image;

void	my_mlx_pixel_put(t_image *data, int x, int y, int color);
void	draw_grid(t_image *data);
void	draw_player(t_image *data);
void	ray_collision(t_image *data);
void	draw_point(t_image *data, int x, int y, int color);
void	set_incrementor(int *incrementor, double alpha);
int		same_position(double ray_positon[2][2]);
int		it_collides(double ray_positon[2][2], t_image *data);
int		check_in_range(double ray_positon[2][2], int collider[2]);
int		out_of_map(double ray_positon[2][2]);
int		ray_diiffers_in_x(double ray_positon[2][2], int	*incrementor);

// TODO should be removed - here only for testing libx
int	main(int argc, char **argv, char **envp)
{
	void	*mlx;
	void	*mlx_win;
	void	*player_img;
	void	*wall_img;
	int		img_width = 900;
	int		img_height = 900;
	t_image	grid;
	
	(void)argc;
	(void)argv;
	(void)envp;
	grid.block[0] = 100;
	grid.block[1] = 700;
	mlx = mlx_init();
	player_img = mlx_xpm_file_to_image(mlx, "images/player.xpm", &img_width, &img_height);
	wall_img = mlx_xpm_file_to_image(mlx, "images/wall.xpm", &img_width, &img_height);
	if (!player_img || !wall_img)
	{
		printf("ERROR");
		return (0);
	}
	mlx_win = mlx_new_window(mlx, 900, 900, "Hello world!");
	grid.img = mlx_new_image(mlx, 900, 900);
	grid.addr = mlx_get_data_addr(grid.img, &grid.bits_per_pixel, \
		&grid.line_length, &grid.endian);
	draw_grid(&grid);
	ray_collision(&grid);
	mlx_put_image_to_window(mlx, mlx_win, grid.img, 0, 0);
	mlx_put_image_to_window(mlx, mlx_win, wall_img, grid.block[0], grid.block[1]);
	(void)mlx_win;
	mlx_loop(mlx);
}

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_grid(t_image *data)
{
	int 	i;
	int 	j;

	j = 0;
	while(j < 900)
	{
		i = 0;
		while(i < 900)
		{
			my_mlx_pixel_put(data, j, i, 0x00FF0000);
			i++;
		}
		j += 100;
	}
	j = 0;
	while(j < 900)
	{
		i = 0;
		while(i < 900)
		{
			my_mlx_pixel_put(data, i, j, 0x00FF0000);
			i++;
		}
		j += 100;
	}
}

void	draw_player(t_image *data)
{
	int	i;
	int	j;

	j = 295;
	while(j < 305)
	{
		i = 295;
		while(i < 305)
		{
			my_mlx_pixel_put(data, i, j, 0x0000FF00);
			i++;
		}
		j += 1;
	}
}

void	draw_point(t_image *data, int x, int y, int color)
{
	int	x_aux;
	int	y_aux;

	y_aux = y - 5;
	while(y_aux < (y + 5))
	{
		x_aux = x - 5;
		while(x_aux < (x + 5))
		{
			my_mlx_pixel_put(data, x_aux, y_aux, color);
			x_aux++;
		}
		y_aux++;
	}
}

void	ray_collision_old(t_image *data)
{
	(void)data;
	double	x1;
	double	y1;
	double	x2;
	double	y2;
	double	m, n, r;
	int		i;

	x1 = 300;
	y1 = 300;
	x2 = 650;
	y2 = 150;
	m = (y2 - y1) / (x2 - x1);
	n = y1 - (x1 * m);
	r = (m * 400) + n;
	printf("RESULT: %f\n", r);
	i = 0;
	while(i < 20)
	{
		my_mlx_pixel_put(data, (400 - 10) + i, r, 0x0000FF00);
		i++;
	}
	r = (m * 500) + n;
	printf("RESULT: %f\n", r);
	i = 0;
	while(i < 20)
	{
		my_mlx_pixel_put(data, (500 - 10) + i, r, 0x0000FF00);
		i++;
	}
	r = (m * 600) + n;
	printf("RESULT: %f\n", r);
	i = 0;
	while(i < 20)
	{
		my_mlx_pixel_put(data, (600 - 10) + i, r, 0x0000FF00);
		i++;
	}
}

void	ray_collision(t_image *data)
{
	double	point[2];
	double	ray_positon[2][2];
	double	alpha;
	double	m;
	double	n;
	int		*incrementor;

	point[0] = 500;
	point[1] = 500;
	draw_point(data, point[0], point[1], 0x00ff0000);

	//Ray Info
	incrementor = calloc(2, sizeof(double));
	//alpha = (1.0 / 4.8) * M_PI;
	alpha = (3.3 / 4.0) * M_PI;
	printf("Alpha value: %lf\n", alpha);
	set_incrementor(incrementor, alpha);
	printf("Incrementor: (%d, %d)\n", incrementor[0], incrementor[1]);
	m = tan(alpha);
	n = point[1] - (point[0] * m);
	ray_positon[0][0] = point[0];
	ray_positon[0][1] = point[1];
	ray_positon[1][0] = point[0];
	ray_positon[1][1] = point[1];
	while(!it_collides(ray_positon, data) && !out_of_map(ray_positon))
	{
		printf("Before:\nRAY1: %lf,%lf\n", ray_positon[0][0], ray_positon[0][1]);
		printf("RAY2: %lf,%lf\n", ray_positon[1][0], ray_positon[1][1]);

		//if ((int)ray_positon[0][0] <= (int)ray_positon[1][0])
		if (ray_diiffers_in_x(ray_positon, incrementor))
		{
			printf("SAME\n\n");
			ray_positon[0][0] += (double)(incrementor[0] * 100);
			ray_positon[0][1] = (m * ray_positon[0][0]) + n;
			if (out_of_map(ray_positon))
				break ;
			draw_point(data, (int)ray_positon[0][0], (int)ray_positon[0][1], 0x0000ff00);
		}
		else
		{
			printf("DIF\n\n");
			ray_positon[1][1] += (double)(incrementor[1] * 100);
			ray_positon[1][0] = (ray_positon[1][1] - n) / m;
			if (out_of_map(ray_positon))
				break ;
			draw_point(data, (int)ray_positon[1][0], (int)ray_positon[1][1], 0x000000FF);
		}
		printf("After:\nRAY1: %lf,%lf\n", ray_positon[0][0], ray_positon[0][1]);
		printf("RAY2: %lf,%lf\n\n\n", ray_positon[1][0], ray_positon[1][1]);
	}
	free(incrementor);
}

void	set_incrementor(int *incrementor, double alpha)
{
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

int	same_position(double ray_positon[2][2])
{
	if ((int)ray_positon[0][0] <= (int)ray_positon[1][0])
		return(1);
	if ((int)ray_positon[0][0] == (int)ray_positon[1][0])
		if (ray_positon[0][1] == ray_positon[1][1])
			return (1);
	return (0);
}

int	it_collides(double ray_positon[2][2], t_image *data)
{
	int collider[2];

	collider[0] = data->block[0];
	collider[1] = data->block[1];
	if(check_in_range(ray_positon, collider))
	{
		printf("\n\nCollision with wall in (%d,%d)\n\n", collider[0], collider[1]);
		return (1);
	}
	return (0);
}

int	check_in_range(double ray_positon[2][2], int collider[2])
{
	int i;

	i = 0;
	while(i < 2)
	{
		if (ray_positon[i][0] >= collider[0] \
			&& ray_positon[i][0] <= (collider[0] + 100))
			if (ray_positon[i][1] >= collider[1] \
			&& ray_positon[i][1] <= (collider[1] + 100))
				return (1);
		i++;
	}
	return (0);
}

int	out_of_map(double ray_positon[2][2])
{
	int i;

	i = 0;
	while(i < 2)
	{
		if (ray_positon[i][0] > 900 || ray_positon[i][1] > 900 || \
			ray_positon[i][0] < 100 || ray_positon[i][1] < 100)
			return (1);
		i++;
	}
	return (0);
}

int	ray_diiffers_in_x(double ray_positon[2][2], int	*incrementor)
{
	if (incrementor[0] == 1)
	{
		if ((int)ray_positon[0][0] <= (int)ray_positon[1][0])
			return (1);
	}
	if (incrementor[0] == -1)
	{
		if ((int)ray_positon[0][0] >= (int)ray_positon[1][0])
			return (1);
	}
	return (0);
}