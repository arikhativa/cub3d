/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:24:44 by ycarro            #+#    #+#             */
/*   Updated: 2023/02/07 12:28:54 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void arg_check(int argc, char **argv)
{
	check_arg_count(argc);
	check_first_arg(argv[1]);
}

void	check_arg_count(int argc)
{
	if (argc < 2)
	{
		printf("%s\n", "ERROR: '.cub' map not specified\n");
		exit(1);
	}
	if (argc > 2)
	{
		printf("%s\n", "ERROR: Too many arguments, program only requires a map...\n");
		exit(1);
	}
}


int	check_first_arg(char *file_name)
{
	check_extension(file_name);
}

void	check_extension(char *file_name)
{
	char *extension;
	int	filename_len;
	int position;
	int i;

	extension = ft_calloc(5, sizeof(char));
	filename_len = ft_strlen(file_name);
	position = 0;
	i = 3;
	while(i >= 0)
	{
		extension[position] = file_name[(filename_len - 1) - i];
		position++;
		i--;
	}
	if(filename_len < 5 || ft_strncmp(extension, ".cub", 4))
	{
		printf("%s\n", "ERROR: Invalid map format\n");
		printf("%s\n", "Map format should be: map_name.cub\n");
		exit(1);
	}
}