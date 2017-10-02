/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_cmd_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 11:44:16 by eterman           #+#    #+#             */
/*   Updated: 2017/02/19 21:37:33 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	togle_bool(int *val)
{
	*val = !(*val);
}

static void	select_option(int option_index, t_select *data)
{
	togle_bool(&(get_option(option_index)->is_selected));
	rewrite_option(option_index, 0, get_effects(data->cursor_pos, 0));
}

int			key_cmd_space(t_select *data)
{
	if (data->must_refresh)
	{
		data->must_refresh = 0;
		refresh_output();
		return (0);
	}
	select_option(data->cursor_pos, data);
	key_cmd_down(data);
	return (0);
}
