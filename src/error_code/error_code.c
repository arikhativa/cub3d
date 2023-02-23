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

static t_error_code	error_code_print_msg(char *msg, t_error_code err)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
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

static t_error_code	error_code_print_ext2(t_error_code err)
{
	if (EXT_INVALID_LINE == err)
		err = error_code_print_msg(EXT_INVALID_LINE_MSG, err);
	else if (EXT_BAD_COLOR == err)
		err = error_code_print_msg(EXT_BAD_COLOR_MSG, err);
	else if (EXT_MISSING_PLANE_COLOR == err)
		err = error_code_print_msg(EXT_MISSING_PLANE_COLOR_MSG, err);
	else if (EXT_BAD_CHAR_IN_PLANE == err)
		err = error_code_print_msg(EXT_BAD_CHAR_IN_PLANE_MSG, err);
	else if (EXT_BAD_SPRITE_FILE == err)
		err = error_code_print_msg(EXT_BAD_SPRITE_FILE_MSG, err);
	else if (EXT_BAD_PREFIX == err)
		err = error_code_print_msg(EXT_BAD_PREFIX_MSG, err);
	else if (EXT_TOO_MANY_ARG == err)
		err = error_code_print_msg(EXT_TOO_MANY_ARG_MSG, err);
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
	else if (EXT_MAP_NOT_AT_BOTTOM == err)
		err = error_code_print_msg(EXT_MAP_NOT_AT_BOTTOM_MSG, err);
	else if (EXT_INVALID_FILE == err)
		err = error_code_print_msg(EXT_INVALID_FILE_MSG, err);
	else if (OPEN_ERROR == err)
	{
		err = error_code_print_msg(OPEN_ERROR_MSG, err);
		perror("");
	}
	return (error_code_print_ext2(err));
}

t_error_code	error_code_print_on_exit(t_error_code err)
{
	err = error_code_print_external_err(err);
	if (SUCCESS != err)
		err = error_code_print_internal_err(err);
	return (err);
}
