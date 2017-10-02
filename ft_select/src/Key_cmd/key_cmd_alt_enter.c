/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_cmd_alt_enter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 20:59:34 by eterman           #+#    #+#             */
/*   Updated: 2017/02/19 21:36:31 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int				key_cmd_alt_enter(t_select *data)
{
	if (data->is_in_find_mode)
	{
		select_matches(data->options);
		refresh_output();
	}
	if (data->must_refresh)
	{
		data->must_refresh = 0;
		refresh_output();
	}
	return (0);
}
