/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_cursor_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 16:55:29 by eterman           #+#    #+#             */
/*   Updated: 2017/02/19 14:48:49 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
** A function used for arrow keys.
*/

/*
** Was out of lines
*/

static int		get_horz_pos(int x, int pos, t_select *data, int nr_of_options)
{
	if (pos + x * data->win_height >= nr_of_options)
		pos = pos % data->win_height;
	else if (pos + x * data->win_height < 0)
	{
		pos = nr_of_options / data->win_height *
			data->win_height + pos % data->win_height;
		if (pos >= nr_of_options)
			pos -= data->win_height;
	}
	else
		pos += x * data->win_height;
	return (pos);
}

void			change_cursor_pos(t_select *data, int x, int y)
{
	int		nr_of_options;
	int		pos;

	rewrite_option(data->cursor_pos, 0, get_effects(data->cursor_pos, 0));
	nr_of_options = ft_lstlen(data->options);
	pos = data->cursor_pos;
	if (x)
		pos = get_horz_pos(x, pos, data, nr_of_options);
	if (y)
	{
		if (pos + y >= nr_of_options)
			pos = 0;
		else if (pos + y < 0)
			pos = nr_of_options - 1;
		else
			pos += y;
	}
	data->cursor_pos = pos;
	rewrite_option(pos, 0, get_effects(pos, 1));
}
