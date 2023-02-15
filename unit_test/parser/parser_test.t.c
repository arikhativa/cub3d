/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_test.t.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:21:17 by yoav              #+#    #+#             */
/*   Updated: 2023/02/15 11:07:33 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "unit_test.h"

void	test_parser(void)
{
	t_error_code	ret;

	ret = parser_check_arg_count(2);
	CU_ASSERT_EQUAL(SUCCESS, ret);
	ret = parser_check_arg_count(3);
	CU_ASSERT_EQUAL(EXT_TOO_MANY_ARG, ret);
	ret = parser_check_arg_count(0);
	CU_ASSERT_EQUAL(EXT_NO_ARG, ret);
}

void	test_suffix(void)
{
	char	bad_ext[] = "file.tv";
	char	good_ext[] = "file.cub";
	t_error_code	err;

	err = parser_check_first_arg(good_ext);
	CU_ASSERT_EQUAL(err, SUCCESS);
	err = parser_check_first_arg(bad_ext);
	CU_ASSERT_EQUAL(err, EXT_INVALID_FILE);
}
