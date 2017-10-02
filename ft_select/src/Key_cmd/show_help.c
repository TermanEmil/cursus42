/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 21:42:08 by eterman           #+#    #+#             */
/*   Updated: 2017/02/19 23:04:31 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int				show_help(t_select *data)
{
	(void)data;
	ft_clear_screen();
	cursor_goto(0, 0);
	print_help_text(FD_WR);
	data->must_refresh = 1;
	return (0);
}
