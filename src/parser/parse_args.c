/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:10:50 by yrabby            #+#    #+#             */
/*   Updated: 2023/02/15 12:10:50 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_error_code	parser_arg_check(int argc, char **argv)
{
	t_error_code	err;

	err = parser_check_arg_count(argc);
	if (SUCCESS == err)
		err = parser_check_first_arg(argv[1]);
	return (err);
}

t_error_code	parser_check_arg_count(int argc)
{
	if (argc < 2)
		return (EXT_NO_ARG);
	if (argc > 2)
		return (EXT_TOO_MANY_ARG);
	return (SUCCESS);
}

t_error_code	parser_check_first_arg(char *file_name)
{
	t_error_code	err;

	err = parser_check_extension(file_name);
	if (SUCCESS == err)
	{
		if (!file_mngr_is_file(file_name))
			return (EXT_NO_FILE);
	}
	return (err);
}

t_error_code	parser_check_extension(char *file_name)
{
	char	*extension;
	int		filename_len;
	int		position;
	int		i;

	extension = ft_calloc(5, sizeof(char));
	filename_len = ft_strlen(file_name);
	position = 0;
	i = 3;
	while (i >= 0)
	{
		extension[position] = file_name[(filename_len - 1) - i];
		position++;
		i--;
	}
	if (filename_len < 5 || ft_strncmp(extension, ".cub", 4))
	{
		free(extension);
		return (EXT_INVALID_FILE);
	}
	free(extension);
	return (SUCCESS);
}
