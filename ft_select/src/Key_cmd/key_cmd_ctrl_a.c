/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_cmd_ctrl_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 14:23:00 by eterman           #+#    #+#             */
/*   Updated: 2017/02/19 14:54:14 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	everything_is_selected(t_list *options)
{
	while (options)
	{
		if (!LCONT(options, t_option*)->is_selected)
			return (0);
		LTONEXT(options);
	}
	return (1);
}

int			key_cmd_ctrl_a(t_select *data)
{
	change_select_value(data->options, !everything_is_selected(data->options));
	refresh_output();
	return (0);
}
