/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:24:44 by ycarro            #+#    #+#             */
/*   Updated: 2023/02/13 12:30:40 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# include "error_code.h"
# include "libft.h"

t_error_code	parser_arg_check(int argc, char **argv);
t_error_code	parser_check_arg_count(int argc);
t_error_code	parser_check_first_arg(char *file_name);
t_error_code	parser_check_extension(char *file_name);

#endif