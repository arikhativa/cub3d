/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:54:54 by yrabby            #+#    #+#             */
/*   Updated: 2022/11/21 11:38:34 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dll.h"

t_dll	*dll_get_last_elem(t_dll *lst)
{
	register t_dll	*next;

	if (!lst)
		return (NULL);
	next = lst->next;
	while (next)
	{
		lst = next;
		next = lst->next;
	}
	return (lst);
}

int	dll_is_first_elem(t_dll *lst)
{
	if (!lst)
		return (FALSE);
	return (NULL == lst->prev);
}
