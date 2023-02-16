/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:56:02 by yoav              #+#    #+#             */
/*   Updated: 2023/02/16 10:48:12 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIT_TEST_H
# define UNIT_TEST_H

# include <stdio.h>
# include <string.h>
# include "CUnit/Basic.h"

# include "error_code.h"

# define TEST_RES "unit_test_tmp.txt"

extern CU_SuiteInfo	g_suites[];
extern CU_TestInfo	g_sprite_mngr_tests[];
extern CU_TestInfo	g_sprite_tests[];
extern CU_TestInfo	g_map_tests[];
extern CU_TestInfo	g_player_tests[];
extern CU_TestInfo	g_point_tests[];
extern CU_TestInfo	g_dll_tests[];
extern CU_TestInfo	g_parser_tests[];

extern void	*g_mlx;

// main
int		init_suite(void);
int		clean_suite(void);

// dll tests
void	test_dll_add_before(void);
void	test_dll_swap_value(void);
void	test_dll_create_and_destroy_elem(void);
void	test_dll_clear_list(void);
void	test_dll_add_last(void);
void	test_dll_add_after(void);
void	test_dll_get_last_elem(void);
void	test_dll_remove_first_elem(void);
void	test_dll_remove_last_elem(void);
void	test_dll_remove_elem(void);

// parser tests
void	test_parser(void);
void	test_suffix(void);

// point
void	test_point(void);

// player
void	test_player_create_destroy(void);
void	test_player_init(void);

// map
void	test_map_create_destroy(void);

// player
void	test_player_create_destroy(void);

// point
void	test_point_init(void);

// sprite
void	test_sprite_create_destroy(void);
void	test_sprite_is_loaded(void);

// sprite_mngr
void	test_sprite_mngr_create_destroy(void);

#endif
