/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_selected.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 21:16:11 by eterman           #+#    #+#             */
/*   Updated: 2017/02/19 21:25:18 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int				delete_selected(t_select *data)
{
	t_list		*options;
	int			i;

	options = data->options;
	i = 0;
	while (options)
	{
		if (LCONT(options, t_option*)->is_selected)
		{
			delete_option(i);
			options = data->options;
			i = 0;
		}
		else
		{
			LTONEXT(options);
			i++;
		}
	}
	if (data->cursor_pos >= ft_lstlen(data->options))
		data->cursor_pos = 0;
	if (ft_lstlen(data->options) == 0)
		return (1);
	refresh_output();
	return (0);
}
