/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test_util.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:20:37 by yoav              #+#    #+#             */
/*   Updated: 2022/11/22 11:06:12 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIT_TEST_UTIL_H
# define UNIT_TEST_UTIL_H

# include <stdarg.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include "libft.h"
# include "tab.h"
# include "error_code.h"
# include "unit_test.h"

char	**util_create_tab(int size, ...);
void	util_check_file_and_remove(char *filename);
void	util_read_msg_from_read(char *file, char *msg);

#endif
