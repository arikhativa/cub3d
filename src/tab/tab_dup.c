/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:08:43 by yoav              #+#    #+#             */
/*   Updated: 2022/10/16 10:28:40 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tab.h"

static t_error_code	dup_by_line(char **dst, char **src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = ft_strdup(src[i]);
		if (!dst)
			return (ALLOCATION_ERROR);
		++i;
	}
	return (SUCCESS);
}

t_error_code	tab_dup(char ***dst, char **src)
{
	t_error_code	err;
	size_t			size;
	char			**new;

	size = tab_count(src);
	err = tab_create(&new, size + 1);
	if (SUCCESS != err)
		return (err);
	dup_by_line(new, src);
	*dst = new;
	return (SUCCESS);
}
