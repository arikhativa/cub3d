/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.t.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:21:17 by yoav              #+#    #+#             */
/*   Updated: 2023/02/15 14:02:49 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "unit_test.h"

void	test_map_create_destroy(void)
{
	t_error_code	err;
	t_map			*obj;

	err = map_create(&obj);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	map_destroy(&obj);
	CU_ASSERT_PTR_NULL(obj);
}
