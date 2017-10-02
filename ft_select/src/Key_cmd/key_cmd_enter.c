/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_cmd_enter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 11:44:58 by eterman           #+#    #+#             */
/*   Updated: 2017/02/19 21:37:22 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			key_cmd_enter(t_select *data)
{
	(void)data;
	if (data->must_refresh)
	{
		data->must_refresh = 0;
		refresh_output();
		return (0);
	}
	return (1);
}
