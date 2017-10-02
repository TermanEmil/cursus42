/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_cmd_bakspace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 19:52:39 by eterman           #+#    #+#             */
/*   Updated: 2017/02/19 19:58:46 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			key_cmd_bakspace(t_select *data)
{
	if (data->is_in_find_mode)
	{
		add_char_to_find_input(data, BACKSPACE[0]);
	}
	else
	{
		key_cmd_del(data);
	}
	return (0);
}
