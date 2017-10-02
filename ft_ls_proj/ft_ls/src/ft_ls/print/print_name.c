/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 14:11:33 by eterman           #+#    #+#             */
/*   Updated: 2017/01/07 14:40:43 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_n_spaces(int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		ft_putchar(' ');
		i++;
	}
}

void		print_left_pivoted(int max_len, char *str, t_ls_data *ls_data)
{
	ft_putstr(str);
	if (!color_is_disabled(ls_data))
		ft_printf("{eoc}");
	print_n_spaces(max_len - ft_strlen(str));
}

void		print_name(
				t_fileinfo *fileinfo,
				t_ls_data *ls_data,
				int max_len,
				int left_pivot)
{
	if (!color_is_disabled(ls_data))
		print_color(get_name_color(fileinfo));
	if (left_pivot)
		print_left_pivoted(max_len, get_name(fileinfo), ls_data);
	else
		ft_printf("%*s", max_len, get_name(fileinfo));
	if (!color_is_disabled(ls_data))
		ft_printf("{eoc}");
}
