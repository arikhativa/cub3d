/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:42:34 by yoav              #+#    #+#             */
/*   Updated: 2023/02/15 11:16:30 by yrabby           ###   ########.fr       */
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
