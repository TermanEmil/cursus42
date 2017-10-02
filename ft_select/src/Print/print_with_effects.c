/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_with_effects.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 17:12:32 by eterman           #+#    #+#             */
/*   Updated: 2017/02/19 23:01:54 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "ft_colors.h"

static void	print_effects(int flag)
{
	if (flag & UNDERLINE_FLAG)
		ft_tputs("us");
	if (flag & SELECT_FLAG)
		ft_putstr_fd(REVERSE_VIDEO, FD_WR);
}

static void	remove_effects(int flag)
{
	if (flag & UNDERLINE_FLAG)
		ft_tputs("ue");
	if (flag & SELECT_FLAG)
		ft_putstr_fd(EOC, FD_WR);
}

static void	print_front_cursor(char *text, int flag)
{
	if (get_select_data(NULL)->is_in_find_mode &&
		ft_match(text, get_select_data(NULL)->find_input))
	{
		print_n_times(" ",
			ft_strlen(CURSOR_FRONT) - ft_strlen(CURSOR_MATCH), FD_WR);
		ft_putstr_fd(CURSOR_MATCH, FD_WR);
	}
	else if (flag & UNDERLINE_FLAG)
		ft_putstr_fd(CURSOR_FRONT, FD_WR);
	else
		print_n_times(" ", ft_strlen(CURSOR_FRONT), FD_WR);
}

void		print_with_effects(char *text, int flag)
{
	char	*color;

	print_front_cursor(text, flag);
	print_effects(flag);
	color = get_color(text);
	if (color)
		ft_putstr_fd(color, FD_WR);
	ft_putstr_fd(text, FD_WR);
	if (color)
		ft_putstr_fd(C_EOC, FD_WR);
	remove_effects(flag);
	if (flag & UNDERLINE_FLAG)
		ft_putstr_fd(CURSOR_END, FD_WR);
	else
		print_n_times(" ", ft_strlen(CURSOR_END), FD_WR);
}
