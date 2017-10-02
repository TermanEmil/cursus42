/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 18:57:43 by eterman           #+#    #+#             */
/*   Updated: 2017/02/19 23:01:03 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	print_option(t_option *option, int col_len, int is_cursored)
{
	int		effects;

	effects = 0;
	if (is_cursored)
		effects |= UNDERLINE_FLAG;
	if (option->is_selected)
		effects |= SELECT_FLAG;
	print_with_effects(option->value, effects);
	print_n_times(" ", col_len - ft_strlen(option->value), FD_WR);
}

void		print_options(t_select *data)
{
	int		col_len;
	t_list	*options;
	int		i;

	col_len = data->col_len;
	options = data->options;
	i = 0;
	while (options)
	{
		if (goto_option(i, data))
			return ;
		print_option(LCONT(options, t_option*), col_len, data->cursor_pos == i);
		LTONEXT(options);
		i++;
	}
}
