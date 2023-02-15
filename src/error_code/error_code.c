/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:42:34 by yoav              #+#    #+#             */
/*   Updated: 2023/02/15 11:07:49 by yrabby           ###   ########.fr       */
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

static t_error_code	error_code_print_msg(char *msg, t_error_code err)
{
	ft_putstr_fd(CUB3D_STR, STDERR_FILENO);
	ft_putstr_fd(": ERROR_CODE: ", STDERR_FILENO);
	ft_putnbr_fd(err, STDERR_FILENO);
	ft_putstr_fd(NEW_LINE_STR, STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd(NEW_LINE_STR, STDERR_FILENO);
	return (SUCCESS);
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

t_error_code	error_code_print_external_err(t_error_code err)
{
	if (SUCCESS == err)
		return (SUCCESS);
	if (EXT_NO_ARG == err)
		err = error_code_print_msg(EXT_NO_ARG_MSG, err);
	else if (EXT_TOO_MANY_ARG == err)
		err = error_code_print_msg(EXT_TOO_MANY_ARG_MSG, err);
	else if (EXT_INVALID_FILE == err)
		err = error_code_print_msg(EXT_INVALID_FILE_MSG, err);
	return (err);
}

t_error_code	error_code_print_on_exit(t_error_code err)
{
	err = error_code_print_external_err(err);
	if (SUCCESS != err)
		err = error_code_print_internal_err(err);
	return (err);
}
