/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_cmd_esc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 11:43:29 by eterman           #+#    #+#             */
/*   Updated: 2017/02/19 21:37:09 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			key_cmd_esc(t_select *data)
{
	if (data->is_in_find_mode)
	{
		data->is_in_find_mode = 0;
		refresh_output();
		return (0);
	}
	else if (data->must_refresh)
	{
		data->must_refresh = 0;
		refresh_output();
		return (0);
	}
	change_select_value(data->options, 0);
	return (1);
}
