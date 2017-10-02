/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_output.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 21:26:13 by eterman           #+#    #+#             */
/*   Updated: 2017/04/02 17:49:24 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	update_screen_size(t_select *data)
{
	struct winsize	win;

	ioctl(0, TIOCGWINSZ, &win);
	data->win_height = win.ws_row - data->is_in_find_mode;
	data->win_width = win.ws_col;
}

void		refresh_output(void)
{
	update_screen_size(get_select_data(NULL));
	update_col_len(get_select_data(NULL));
	ft_clear_screen();
	print_options(get_select_data(NULL));
	if (get_select_data(NULL)->is_in_find_mode)
		update_find(get_select_data(NULL));
}
