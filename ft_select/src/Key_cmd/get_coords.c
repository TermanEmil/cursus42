/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 12:13:24 by eterman           #+#    #+#             */
/*   Updated: 2017/02/19 16:48:36 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			get_coords(int *x, int *y, int index, t_select *data)
{
	if (data->win_height <= 0 || data->win_width <= 0)
		return (-1);
	*x = (index / data->win_height) * data->col_len;
	*y = index % data->win_height;
	if (*x + data->col_len + (int)ft_strlen(CURSOR_FRONT) > data->win_width ||
		*y > data->win_height)
		return (-1);
	return (0);
}
