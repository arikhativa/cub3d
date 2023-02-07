/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_suites.t.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:22:13 by yoav              #+#    #+#             */
/*   Updated: 2023/02/07 10:55:13 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

CU_SuiteInfo	g_suites[] = {
{
	"dll",
	init_suite,
	clean_suite,
	NULL,
	NULL,
	g_dll_tests,
},
	CU_SUITE_INFO_NULL,
};
