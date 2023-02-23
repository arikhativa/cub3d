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

#include "file_mngr.h"

t_error_code	file_mngr_open(int *ret, char *path)
{
	int	fd;

	if (!ret || !path)
		return (NULL_POINTER);
	fd = open(path, O_RDONLY);
	if (ERROR == fd)
		return (OPEN_ERROR);
	*ret = fd;
	return (SUCCESS);
}

t_bool	file_mngr_is_file(char *path)
{
	t_error_code	err;
	int				fd;

	err = file_mngr_open(&fd, path);
	if (SUCCESS == err)
	{
		close(fd);
		return (TRUE);
	}
	return (FALSE);
}
