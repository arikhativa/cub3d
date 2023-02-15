/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:42:34 by yoav              #+#    #+#             */
/*   Updated: 2023/02/15 10:34:32 by yrabby           ###   ########.fr       */
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

static void	error_code_print_msg(char *msg, t_error_code err)
{
	ft_putstr_fd(CUB3D_STR, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putnbr_fd(err, STDERR_FILENO);
	ft_putstr_fd(NEW_LINE_STR, STDERR_FILENO);
}

t_error_code	error_code_print_internal_err(t_error_code err)
{
	if (SUCCESS == err)
		return (SUCCESS);
	if (ERROR == err)
		error_code_print_msg("ERROR", err);
	else if (ALLOCATION_ERROR == err)
		error_code_print_msg("ALLOCATION_ERROR", err);
	else
		error_code_print_msg("UNKNOWN_ERROR", err);
	return (err);
}
