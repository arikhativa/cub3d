/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_code2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:42:34 by yoav              #+#    #+#             */
/*   Updated: 2023/04/18 17:46:56 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_code.h"

void	error_code_print(int size, ...)
{
	va_list			list;
	char			*s;
	int				i;

	ft_putstr_fd(CUB3D_STR, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	va_start(list, size);
	i = 0;
	while (i < size)
	{
		s = va_arg(list, char *);
		ft_putstr_fd(s, STDERR_FILENO);
		++i;
	}
	va_end(list);
	ft_putstr_fd(NEW_LINE_STR, STDERR_FILENO);
}

t_error_code	error_code_print_ext3(t_error_code err)
{
	if (EXT_MLX_ERROR == err)
		err = error_code_print_msg(EXT_MLX_ERROR_MSG, err);
	else if (EXT_MISSING_PLAYER == err)
		err = error_code_print_msg(EXT_MISSING_PLAYER_MSG, err);
	else if (EXT_MAP_OPEN == err)
		err = error_code_print_msg(EXT_MAP_OPEN_MSG, err);
	else if (EXT_DUPLICATE_SETTING == err)
		err = error_code_print_msg(EXT_DUPLICATE_SETTING_MSG, err);
	else if (EXT_MAP_TOO_BIG == err)
		err = error_code_print_msg(EXT_MAP_TOO_BIG_MSG, err);
	return (err);
}
