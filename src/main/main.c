/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 09:50:39 by al7aro            #+#    #+#             */
/*   Updated: 2023/04/19 14:32:46 by ycarro           ###   ########.fr       */
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
			err = map_read_raw(game->map, argv[1]);
			if (SUCCESS == err)
				err = game_init(game);
			if (SUCCESS == err)
				err = game_load(game);
			if (SUCCESS == err)
				err = game_start(game);
			game_destroy(&game);
		}
	}
	return (error_code_print_on_exit(err));
}
