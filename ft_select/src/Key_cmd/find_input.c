/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 20:41:47 by eterman           #+#    #+#             */
/*   Updated: 2017/02/19 23:03:15 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
** Prints text as much as it can.
*/

static void		print_at(char *text, int x, t_select *data)
{
	cursor_goto(x, data->win_height);
	while (x < data->win_width && *text)
	{
		ft_putchar_fd(*text, FD_WR);
		text++;
		x++;
	}
}

void			update_find(t_select *data)
{
	cursor_goto(0, data->win_height);
	print_n_times(" ", data->win_width, FD_WR);
	cursor_goto(0, data->win_height);
	print_at("Find: ", 0, data);
	print_at(data->find_input, ft_strlen("Find: "), data);
}

static void		update_matches(t_list *options, t_select *data)
{
	int		i;

	i = 0;
	while (options)
	{
		if (ft_match(LCONT(options, t_option*)->value, data->find_input))
		{
			LCONT(options, t_option*)->matches = 1;
			rewrite_option(i, 0, get_effects(i, data->cursor_pos == i));
		}
		else if (LCONT(options, t_option*)->matches)
		{
			LCONT(options, t_option*)->matches = 0;
			rewrite_option(i, 0, get_effects(i, data->cursor_pos == i));
		}
		i++;
		LTONEXT(options);
	}
}

void			add_char_to_find_input(t_select *data, char c)
{
	char		buf[2];
	char		*input;

	input = data->find_input;
	if (c == BACKSPACE[0])
		input[ft_strlen(input) - 1] = 0;
	else
	{
		if (ft_strlen(input) - 1 == sizeof(data->find_input))
			return ;
		buf[0] = c;
		buf[1] = 0;
		ft_strcat(input, buf);
	}
	update_find(data);
	update_matches(data->options, data);
}

int				key_enter_find_mode(t_select *data)
{
	data->is_in_find_mode = 1;
	refresh_output();
	update_find(data);
	return (0);
}
