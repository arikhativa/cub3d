/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/02/15 13:58:46 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_error_code	map_validate(char **file)
{
	t_error_code	err;

	err = cub_validate_by_line(file);
	if (SUCCESS != err)
		return (err);
	err = cub_validate_map_at_bottom(file);
	return (err);
}
