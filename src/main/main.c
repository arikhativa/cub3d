/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 09:50:39 by al7aro            #+#    #+#             */
/*   Updated: 2023/02/16 11:19:44 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	t_game			*game;
	t_error_code	err;

	err = parser_arg_check(argc, argv);
	if (SUCCESS == err)
	{
		err = game_create(&game);
		if (SUCCESS == err)
		{
			err = game_init(game);
			if (SUCCESS == err)
				err = game_load(game, argv[1]);
			if (SUCCESS == err)
				err = game_start(game);
			game_destroy(&game);
		}
	}
	return (error_code_print_on_exit(err));
}
