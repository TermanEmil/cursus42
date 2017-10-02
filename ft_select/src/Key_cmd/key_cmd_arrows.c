/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_cmd_arrows.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 17:08:33 by eterman           #+#    #+#             */
/*   Updated: 2017/02/19 21:36:54 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			key_cmd_up(t_select *data)
{
	if (data->must_refresh)
	{
		data->must_refresh = 0;
		refresh_output();
	}
	change_cursor_pos(data, 0, -1);
	return (0);
}

int			key_cmd_down(t_select *data)
{
	if (data->must_refresh)
	{
		data->must_refresh = 0;
		refresh_output();
	}
	change_cursor_pos(data, 0, 1);
	return (0);
}

int			key_cmd_left(t_select *data)
{
	if (data->must_refresh)
	{
		data->must_refresh = 0;
		refresh_output();
	}
	change_cursor_pos(data, -1, 0);
	return (0);
}

int			key_cmd_right(t_select *data)
{
	if (data->must_refresh)
	{
		data->must_refresh = 0;
		refresh_output();
	}
	change_cursor_pos(data, 1, 0);
	return (0);
}
