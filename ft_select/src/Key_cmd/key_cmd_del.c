/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_cmd_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 11:44:34 by eterman           #+#    #+#             */
/*   Updated: 2017/02/19 21:38:02 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		delete_option(int option_index)
{
	t_list		*option;

	option = ft_lstget(get_select_data(NULL)->options, option_index);
	ft_lstrm(&(get_select_data(NULL)->options), option, &ft_lst_memdel);
}

int			key_cmd_del(t_select *data)
{
	int		last_pos;
	size_t	len;

	if (data->must_refresh)
	{
		data->must_refresh = 0;
		refresh_output();
		return (0);
	}
	len = ft_lstlen(data->options);
	if (len == 0)
		return (1);
	last_pos = data->cursor_pos;
	delete_option(last_pos);
	if (last_pos + 1 == (int)len)
		data->cursor_pos = 0;
	refresh_output();
	if (len == 1)
		return (1);
	return (0);
}
