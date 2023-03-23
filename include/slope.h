/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/02/14 10:47:54 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SLOPE_H
# define SLOPE_H

typedef enum e_slope_type
{
	ZERO,
	INFI,
	NEG_ZERO,
	NEG_INFI,
	VALUE,
}	t_slope_type;

typedef struct s_slope
{
	t_slope_type	type;
	double			value;
}	t_slope;

#endif
