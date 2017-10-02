/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_col_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 11:37:30 by eterman           #+#    #+#             */
/*   Updated: 2017/02/19 19:28:16 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		update_col_len(t_select *data)
{
	int		col_len;
	int		tmp;
	t_list	*options;

	col_len = 0;
	options = data->options;
	while (options)
	{
		tmp = ft_strlen(LCONT(options, t_option*)->value);
		if (tmp > col_len)
			col_len = tmp;
		LTONEXT(options);
	}
	data->col_len = col_len + 1 + ft_strlen(CURSOR_FRONT) +
		ft_strlen(CURSOR_END);
}
