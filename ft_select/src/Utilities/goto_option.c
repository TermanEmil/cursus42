/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goto_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 12:18:31 by eterman           #+#    #+#             */
/*   Updated: 2017/02/19 14:43:22 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			goto_option(int option_index, t_select *data)
{
	int		x;
	int		y;

	if (get_coords(&x, &y, option_index, data) == -1)
		return (-1);
	cursor_goto(x, y);
	return (0);
}
