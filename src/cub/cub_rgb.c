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

#include "cub.h"

t_rgb	cub_get_rgb(char *line)
{
	t_rgb	rgb;
	int		n[3];
	int		i;

	i = 0;
	while (*line && !ft_isdigit(*line))
		++line;
	while (*line)
	{
		atoi_overflow(line, &(n[i]));
		while (ft_isdigit(*line))
			++line;
		if (*line == '\0')
			break ;
		++line;
		++i;
	}
	rgb_init(&rgb, n[0], n[1], n[2]);
	return (rgb);
}
