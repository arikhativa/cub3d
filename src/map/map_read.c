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

static char	*get_line(int fd)
{
	int		len;
	char	*line;

	line = get_next_line(fd);
	len = ft_strlen(line);
	if (len > 0)
		line[len - 1] = 0;
	return (line);
}

static t_error_code	read_all_file(t_map *m, int fd)
{
	char			*line;
	t_error_code	err;

	line = get_line(fd);
	err = tab_add(&(m->file), line);
	while (line && SUCCESS == err)
	{
		line = get_line(fd);
		err = tab_add(&(m->file), line);
	}
	return (err);
}

t_error_code	map_read_raw(t_map *m, char *path)
{
	t_error_code	err;
	int				fd;

	err = file_mngr_open(&fd, path);
	if (SUCCESS != err)
		return (err);
	err = tab_create(&(m->file), 1);
	if (SUCCESS != err)
	{
		close(fd);
		return (err);
	}
	err = read_all_file(m, fd);
	if (SUCCESS != err)
		tab_deep_destroy(&(m->file));
	close(fd);
	return (SUCCESS);
}
