/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_test.t.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:21:17 by yoav              #+#    #+#             */
/*   Updated: 2023/02/13 12:55:55 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "unit_test.h"

void	test_parser(void)
{
	int	ret;

	ret = check_arg_count(2);
	CU_ASSERT_EQUAL(0, ret);
	ret = check_arg_count(3);
	CU_ASSERT_EQUAL(-1, ret);
	ret = check_arg_count(0);
	CU_ASSERT_EQUAL(-1, ret);
}
