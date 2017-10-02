/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 14:31:25 by eterman           #+#    #+#             */
/*   Updated: 2017/01/07 14:56:35 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	get_column_max_width(t_list ***list, int column, int h)
{
	int		i;
	int		tmp;
	int		max;

	max = 0;
	i = 0;
	while (i < h && list[i][column])
	{
		tmp = ft_strlen(get_name(FINFO(list[i][column])));
		if (tmp > max)
			max = tmp;
		i++;
	}
	return (max);
}

static int	is_valid_list(
				t_list ***list,
				int width,
				int columns,
				int file_count)
{
	int		required_width;
	int		i;
	int		h;

	h = file_count / columns + (file_count % columns != 0);
	required_width = 0;
	i = 0;
	while (i < columns)
	{
		required_width += get_column_max_width(list, i, h);
		if (i + 1 < columns)
			required_width += 2;
		i++;
	}
	return (required_width <= width);
}

static void	destroy_buff(t_list ***list, int columns, int file_count)
{
	int		h;
	int		i;

	h = file_count / columns + (file_count % columns != 0);
	i = 0;
	while (i < h)
	{
		free(list[i]);
		i++;
	}
	free(list);
}

static void	print_list(
			t_list ***list,
			int columns,
			int file_count,
			t_ls_data *ls_data)
{
	int		i;
	int		j;
	int		h;

	h = file_count / columns + (file_count % columns != 0);
	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < columns)
		{
			if (list[i][j] != NULL)
			{
				print_name(FINFO(list[i][j]), ls_data,
					get_column_max_width(list, j, h), 1);
				if (j + 1 < columns)
					ft_putstr("  ");
			}
			j++;
		}
		ft_putnewl();
		i++;
	}
}

void		simple_print(t_list *files, t_ls_data *ls_data)
{
	t_list	***buff;
	int		columns;
	int		width;
	int		file_count;

	width = get_terminal_width();
	columns = FT_MAX(1, width / 3);
	file_count = ft_lstlen(files);
	buff = split_in_n_columns(files, columns, file_count);
	while (columns > 1 && !is_valid_list(buff, width, columns, file_count))
	{
		destroy_buff(buff, columns, file_count);
		columns--;
		buff = split_in_n_columns(files, columns, file_count);
	}
	print_list(buff, columns, file_count, ls_data);
	destroy_buff(buff, columns, file_count);
}
